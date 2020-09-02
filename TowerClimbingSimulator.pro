#-------------------------------------------------
#
# Project created by QtCreator 2018-07-06T12:50:05
#
#-------------------------------------------------
CONFIG += resources_big
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerClimbingSimulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainpage.cpp \
    roles.cpp \
    gamemap.cpp \
    selecthero.cpp \
    battle.cpp \
    globals.cpp \
    battlefailed.cpp \
    battlewin.cpp \
    gamemap2.cpp \
    gamemap3.cpp \
    finalwin.cpp \
    guide.cpp

HEADERS += \
        mainpage.h \
    card.h \
    roles.h \
    gamemap.h \
    selecthero.h \
    battle.h \
    globals.h \
    battlefailed.h \
    battlewin.h \
    gamemap2.h \
    gamemap3.h \
    finalwin.h \
    guide.h

FORMS += \
        mainpage.ui \
    gamemap.ui \
    selecthero.ui \
    battle.ui \
    battlefailed.ui \
    battlewin.ui \
    gamemap2.ui \
    gamemap3.ui \
    finalwin.ui \
    guide.ui

RESOURCES += \
    pictures.qrc

DISTFILES += \
    Pictures/select.png

RC_ICONS = Pictures/icon.ico
