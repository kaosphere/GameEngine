TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/chouchous/SFML2.5/include
LIBS += -L"/home/chouchous/SFML2.5/lib/" -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp \
    ECS/entity.cpp \
    ECS/component_base.cpp \
    ECS/entitymanager.cpp \
    ECS/system_base.cpp \
    ECS/systemmanager.cpp

HEADERS += \
    ECS/entity.h \
    ECS/component_base.h \
    ECS/entitymanager.h \
    ECS/system_base.h \
    ECS/systemmanager.h \
    Observer/Communicator.h \
    Observer/Message.h \
    Observer/MessageHandler.h \
    Observer/Observer.h
