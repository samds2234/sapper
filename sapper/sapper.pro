#-------------------------------------------------
#
# Project created by QtCreator 2017-02-18T06:54:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sapper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mygame.cpp \
    visualization.cpp \
    dialog.cpp \
    losegame.cpp \
    turning.cpp \
    statistic.cpp

HEADERS  += mainwindow.h \
    mygame.h \
    visualization.h \
    dialog.h \
    losegame.h \
    turning.h \
    statistic.h

FORMS    += mainwindow.ui \
    dialog.ui \
    losegame.ui \
    turning.ui \
    statistic.ui
