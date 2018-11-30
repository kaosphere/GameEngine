TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/chouchous/SFML2.5/include
LIBS += -L"/home/chouchous/SFML2.5/lib/" -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp \
    ECS/entity.cpp \
    ECS/component_base.cpp \
    ECS/entitymanager.cpp

HEADERS += \
    ECS/entity.h \
    ECS/component_base.h \
    ECS/entitymanager.h
