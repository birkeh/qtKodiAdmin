#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T15:40:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtKodiDB
TEMPLATE = app

TRANSLATIONS    = qtKodiDB_de.ts

SOURCES += main.cpp\
        cmainwindow.cpp \
    ckodivideolibrary.cpp \
    ckodilibrary.cpp \
    ctvshowwidget.cpp \
    cmaintabbar.cpp \
    cmaintabwidget.cpp \
    cmusicwidget.cpp \
    cmusicvideoswidget.cpp \
    cmyvideos.cpp \
    cvideowidget.cpp \
    cvideoviewitemdelegate.cpp \
    ckoditextureslibrary.cpp \
    cimage.cpp \
    ccheckboxitemdelegate.cpp

HEADERS  += cmainwindow.h \
    ckodivideolibrary.h \
    ckodilibrary.h \
    ctvshowwidget.h \
    cmaintabbar.h \
    cmaintabwidget.h \
    cmusicwidget.h \
    cmusicvideoswidget.h \
    cmyvideos.h \
    cvideowidget.h \
    cvideoviewitemdelegate.h \
    ckoditextureslibrary.h \
    cimage.h \
    ccheckboxitemdelegate.h \
    common.h

FORMS    += cmainwindow.ui \
    ctvshowwidget.ui \
    cmusicwidget.ui \
    cmusicvideoswidget.ui \
    cvideowidget.ui

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
    icons/Videos.ico \
    icons/empty.ico
