#include <QDebug>
#include <QJsonObject>
#include <QVector>

#include "cardcontroller.h"

#include "src/utils/singleton.h"
#include "src/engine/HttpRequester/httprequester.h"
#include "src/models/CardModel/cardmodel.h"
#include "src/data_structures/network/CardGetRequest/cardgetrequest.h"
#include "src/data_structures/network/CardDoAnswerRequest/carddoanswerrequest.h"
#include "src/config/apiurls.h"
#include "src/config/questcardtypes.h"
#include "src/mappers/CardMapper/cardmapper.h"
#include "src/models/structures/carddetail.h"

CardController* CardController::instance()
{
    return Singleton<CardController>::instance(CardController::createInstance);
}

void CardController::get(const QString& cardId) const
{
    auto handleSuccess = [this](QJsonObject obj){
        CardMapper mapper;
        auto cardDetail = mapper.convertCardDetail(obj);
        cardModel->setCardDetal(cardDetail);

        if (cardDetail.type == config::QuestCardTypes::CHOOSE) {
            auto cardLinkListStruct = mapper.convertCardLinkList(obj);

            auto cardChooseController = new ChooseCardModel();
            auto cardLinksList = new CardLinkList();
            cardChooseController->setLinksList(cardLinksList);

            for (const auto& link: cardLinkListStruct) {
                auto newLink = new CardLink();
                qDebug() << "new link" << link.answer;
                newLink->setAnswer(link.answer);
                cardLinksList->appendLink(newLink);
            }
            cardModel->setController(cardChooseController);
        }
    };

    auto handleError = [](QJsonObject obj) {
        qDebug() << "error" << obj;
    };

    httpRequester->doGet(
                config::apiUrls::card::GET,
                data_structures::CardGetRequest(cardId),
                handleSuccess, handleError);
}

void CardController::doAnswer(const QString& cardId, const QString& answer) const
{
    auto handleSuccess = [this](QJsonObject obj){
        if(obj["nextCardId"].isString()) {
            auto nextCardId = obj["nextCardId"].toString();
            this->get(nextCardId);
        }
    };

    auto handleError = [](QJsonObject obj){
        qDebug() << "error" << obj;
    };

    httpRequester->doPost(
        config::apiUrls::card::DO_ANSWER,
        data_structures::CardDoAnswerRequest(cardId, answer),
        handleSuccess, handleError);
}

CardController* CardController::createInstance()
{
    return new CardController();
}

CardController::CardController(QObject *parent):
    AbstractContoller(parent, HttpRequester::instance()),
    cardModel(CardModel::instance())
{}

