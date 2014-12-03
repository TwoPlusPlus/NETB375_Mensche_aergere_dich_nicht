#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T18:14:19
#
#-------------------------------------------------

QT       += core

QT       -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = Mensche_Aergere_Dich_Nicht
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    field_class.cpp \
    game_class.cpp \
    piece_player_class.cpp

HEADERS += \
    field_class.h \
    game_class.h \
    piece_player_class.h
