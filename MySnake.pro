TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/ncurses.h
LIBS += /usr/include/ncurses_dll.h -lncurses

SOURCES += main.cpp \
    game.cpp \
    snakepart.cpp

HEADERS += \
    game.h \
    mydefinitions.h \
    snakepart.h
