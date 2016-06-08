#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T21:27:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = revers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Board.cpp \
    Dot.cpp \
    Game.cpp \
    graffield.cpp

HEADERS  += mainwindow.h \
    Board.h \
    Dot.h \
    Game.h \
    State.h \
    graffield.h

FORMS    += mainwindow.ui \
    graffield.ui
