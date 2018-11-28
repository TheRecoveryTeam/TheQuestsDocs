QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main.cpp \
    src/models/CardModel/cardmodel.cpp \
    src/engine/App/app.cpp \
    src/models/CardShortModel/cardshortmodel.cpp \
    src/models/CardModel/controllers/abstractcardcontroller.cpp \
    src/models/CardModel/controllers/ChooseCardModel/choosecardmodel.cpp \
    src/models/CardModel/controllers/ChooseCardModel/cardlinklist.cpp \
    src/models/CardModel/controllers/ChooseCardModel/cardlink.cpp \
    src/models/QuestShortModel/questshortmodel.cpp \
    src/models/QuestDetailModel/questdetailmodel.cpp \
    src/models/QuestListModel/questlistmodel.cpp \
    src/models/UserModel/usermodel.cpp \
    src/engine/HttpRequester/httprequester.cpp \
    src/controllers/AbstractController/abstractcontoller.cpp \
    src/controllers/UserController/usercontroller.cpp \
    src/controllers/CardController/cardcontroller.cpp \
    src/controllers/QuestController/questcontroller.cpp \
    src/mappers/CardMapper/cardmapper.cpp \
    src/data_structures/network/CardDoAnswerRequest/carddoanswerrequest.cpp \
    src/data_structures/network/CardDoAnswerResponse/carddoanswerresponse.cpp \
    src/data_structures/network/CardGetRequest/cardgetrequest.cpp \
    src/controllers/UserController/LoginForm/loginform.cpp \
    src/controllers/UserController/SignUpForm/signupform.cpp \
    src/mappers/CardMapper/questmapper.cpp \
    src/mappers/CardMapper/questlistmapper.cpp \
    src/data_structures/network/QuestGetRequest/questgetrequest.cpp \
    src/data_structures/network/QuestCreate/questcreate.cpp \
    src/data_structures/network/QuestGetResources/questgetresources.cpp \
    src/data_structures/network/QuestGetQuestList/questgetquestlist.cpp \
    src/mappers/CardMapper/resourcesmapper.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/models/CardModel/cardmodel.h \
    src/engine/App/app.h \
    src/models/CardShortModel/cardshortmodel.h \
    src/models/CardModel/controllers/abstractcardcontroller.h \
    src/models/CardModel/controllers/ChooseCardModel/choosecardmodel.h \
    src/config/resourcetypes.h \
    src/config/questcardtypes.h \
    src/models/structures/resourceitem.h \
    src/models/CardModel/controllers/ChooseCardModel/cardlinklist.h \
    src/models/CardModel/controllers/ChooseCardModel/cardlink.h \
    src/models/QuestShortModel/questshortmodel.h \
    src/models/QuestDetailModel/questdetailmodel.h \
    src/models/QuestListModel/questlistmodel.h \
    src/models/UserModel/usermodel.h \
    src/config/network.h \
    src/engine/HttpRequester/httprequester.h \
    src/controllers/AbstractController/abstractcontoller.h \
    src/controllers/UserController/usercontroller.h \
    src/controllers/CardController/cardcontroller.h \
    src/utils/call_once.h \
    src/utils/singleton.h \
    src/controllers/QuestController/questcontroller.h \
    src/mappers/CardMapper/cardmapper.h \
    src/data_structures/interfaces/iserializable.h \
    src/data_structures/interfaces/iqueryable.h \
    src/data_structures/network/CardDoAnswerResponse/carddoanswerrequest.h \
    src/data_structures/network/CardDoAnswerResponse/carddoanswerresponse.h \
    src/data_structures/network/CardGetRequest/cardgetrequest.h \
    src/config/apiurls.h \
    src/models/structures/carddetail.h \
    src/models/structures/cardlink.h \
    src/utils/iform.h \
    src/controllers/UserController/LoginForm/loginform.h \
    src/controllers/UserController/SignUpForm/signupform.h \
    src/models/structures/questdetail.h \
    src/mappers/CardMapper/questmapper.h \
    src/models/structures/questlist.h \
    src/models/structures/questshort.h \
    src/mappers/CardMapper/questlistmapper.h \
    src/data_structures/network/QuestGetRequest/questgetrequest.h \
    src/data_structures/network/QuestCreate/questcreate.h \
    src/data_structures/network/QuestGetResources/questgetresources.h \
    src/data_structures/network/QuestGetQuestList/questgetquestlist.h \
    src/mappers/CardMapper/resourcesmapper.h
