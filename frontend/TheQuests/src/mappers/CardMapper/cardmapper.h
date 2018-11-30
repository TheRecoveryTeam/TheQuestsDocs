#ifndef CARDMAPPER_H
#define CARDMAPPER_H

#include <QMap>
#include <QVector>
#include "src/models/CardShortModel/cardshortmodel.h"
#include "src/models/structures/cardlink.h"

class QJsonObject;

namespace structures {
    struct ResourceItem;
    struct CardDetail;
}

class CardMapper
{
public:
    CardMapper() = default;
    structures::CardDetail convertCardDetail(const QJsonObject& obj) const;
    QVector<structures::CardLink> convertCardLinkList(const QJsonObject& obj) const;

private:
    QVector<structures::ResourceItem> convertResourcesList(const QJsonArray& resourcesJsonArr) const;
};

#endif // CARDMAPPER_H