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
    ckodilibrary.cpp \
    cmoviewidget.cpp \
    ctvshowwidget.cpp \
    cmaintabbar.cpp \
    cmaintabwidget.cpp \
    cmusicwidget.cpp \
    cmusicvideoswidget.cpp

HEADERS  += cmainwindow.h \
    ckodivideolibrary.h \
    ckodilibrary.h \
    cmoviewidget.h \
    ctvshowwidget.h \
    cmaintabbar.h \
    cmaintabwidget.h \
    cmusicwidget.h \
    cmusicvideoswidget.h

FORMS    += cmainwindow.ui \
    cmoviewidget.ui \
    ctvshowwidget.ui \
    cmusicwidget.ui \
    cmusicvideoswidget.ui

RESOURCES += \
    qtkodidb.qrc

DISTFILES += \
    icons/TV Shows.png \
    icons/TV Shows.ico \
    icons/Images.png \
    icons/Musics.png \
    icons/TV Shows.png \
    icons/Videos.png \
    icons/Images.ico \
    icons/Musics.ico \
    icons/TV Shows.ico \
    icons/Videos.ico
