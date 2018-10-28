TARGET = model
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects mongoobjects
DEPENDPATH  += ../helpers sqlobjects mongoobjects
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += mongoobjects/userscollectionobject.h
HEADERS += userscollection.h
SOURCES += userscollection.cpp
HEADERS += mongoobjects/questcollectionobject.h
HEADERS += questcollection.h
SOURCES += questcollection.cpp
HEADERS += mongoobjects/cardcollectionobject.h
HEADERS += cardcollection.h
SOURCES += cardcollection.cpp