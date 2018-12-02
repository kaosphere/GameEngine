TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/chouchous/SFML2.5/include
LIBS += -L"/home/chouchous/SFML2.5/lib/" -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp \
    ECS/Core/entity.cpp \
    ECS/Core/system_base.cpp \
    ECS/Core/systemmanager.cpp \
    Utilities/idgenerator.cpp \
    ECS/Components/component_position.cpp \
    ECS/Components/component_speed.cpp

HEADERS += \
    ECS/Core/entity.h \
    ECS/Core/component_base.h \
    ECS/Core/system_base.h \
    ECS/Core/systemmanager.h \
    ECS/Core/componenttypes.h \
    Observer/Communicator.h \
    Observer/Message.h \
    Observer/MessageHandler.h \
    Observer/Observer.h \
    Utilities/Helpers.h \
    Utilities/RandomGenerator.h \
    Utilities/Utilities.h \
    Utilities/idgenerator.h \
    ECS/Components/component_position.h \
    ECS/Components/component_speed.h \
    ECS/Core/systemtypes.h
