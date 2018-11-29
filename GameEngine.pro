TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/alex/SFML2.5/include
LIBS += -L"/home/alex/SFML2.5/lib/" -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp

HEADERS += \
