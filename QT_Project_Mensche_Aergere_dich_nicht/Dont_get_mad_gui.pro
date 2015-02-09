#-------------------------------------------------
#
# Project created by QtCreator 2015-01-12T10:42:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dont_get_mad_gui
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    primarydialog.cpp \
    newgamedialog.cpp \
    loaddialog.cpp \
    settingsdialog.cpp \
    rulesdialog.cpp \
    classicboarddialog.cpp \
    player_ai_class.cpp \
    field_piece_class.cpp \
    game_class.cpp \
    windialog.cpp

HEADERS  += mainwindow.h \
    primarydialog.h \
    newgamedialog.h \
    loaddialog.h \
    settingsdialog.h \
    rulesdialog.h \
    classicboarddialog.h \
    player_ai_class.h \
    field_piece_class.h \
    game_class.h \
    windialog.h

FORMS    += mainwindow.ui \
    primarydialog.ui \
    newgamedialog.ui \
    loaddialog.ui \
    settingsdialog.ui \
    rulesdialog.ui \
    classicboarddialog.ui \
    windialog.ui

RESOURCES += \
    req.qrc
