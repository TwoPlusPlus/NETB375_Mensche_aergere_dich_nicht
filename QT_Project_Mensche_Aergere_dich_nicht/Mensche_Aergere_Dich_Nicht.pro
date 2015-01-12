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
    game_class.cpp \
    field_piece_class.cpp \
    player_ai_class.cpp

HEADERS += \
    game_class.h \
    field_piece_class.h \
    player_ai_class.h
