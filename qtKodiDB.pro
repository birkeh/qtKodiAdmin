#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T15:40:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtKodiDB
TEMPLATE = app


SOURCES += main.cpp\
        cmainwindow.cpp \
    ckodivideolibrary.cpp \
    ckodilibrary.cpp

HEADERS  += cmainwindow.h \
    ckodivideolibrary.h \
    ckodilibrary.h

FORMS    += cmainwindow.ui

RESOURCES += \
    qtkodidb.qrc

DISTFILES += \
    icons/Images.png \
    icons/Musics.png \
    icons/TV Shows.png \
    icons/Videos.png \
    icons/Images.ico \
    icons/Musics.ico \
    icons/TV Shows.ico \
    icons/Videos.ico
