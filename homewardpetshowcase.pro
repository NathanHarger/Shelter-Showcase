#-------------------------------------------------
#
# Project created by QtCreator 2015-12-08T00:22:38
#
#-------------------------------------------------

QT       += core gui
QT         += qml quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homewardpetshowcase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animallistmodel.cpp \
    apimanager.cpp \
    configuration.cpp \
    animal.cpp

HEADERS  += mainwindow.h \
    animallistmodel.h \
    apimanager.h \
    configuration.h \
    animal.h

FORMS

DISTFILES +=

    FindShelterId.py

RESOURCES += \
    model.qrc