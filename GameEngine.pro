TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#INCLUDEPATH += /home/chouchous/SFML-2.5.0/include
LIBS += -lsfml-graphics -lsfml-window -lsfml-system

QMAKE_CXXFLAGS += -Wreorder

SOURCES += main.cpp \
    ECS/Core/entity.cpp \
    ECS/Core/system_base.cpp \
    ECS/Core/systemmanager.cpp \
    Utilities/idgenerator.cpp \
    ECS/Components/component_position.cpp \
    ECS/Components/component_speed.cpp \
    ECS/Systems/system_move.cpp \
    ThreadWorkers/FileLoader.cpp \
    ECS/Systems/system_renderer.cpp \
    Map/tile.cpp \
    Map/map.cpp \
    Utilities/SimplexNoise.cpp \
    Map/mapgenerator.cpp \
    WindowSystem/Renderer.cpp \
    StateSystem/StateManager.cpp \
    StateSystem/States/State_Loading.cpp \
    game.cpp \
    StateSystem/States/State_Game.cpp \
    EventSystem/EventManager.cpp \
    Utilities/FastNoise.cpp \
    GUI/Elements/GUI_CheckBox.cpp \
    GUI/Elements/GUI_DropDownMenu.cpp \
    GUI/Elements/GUI_Label.cpp \
    GUI/Elements/GUI_Scrollbar.cpp \
    GUI/Elements/GUI_Sprite.cpp \
    GUI/Elements/GUI_TextField.cpp \
    GUI/Specialized/FileManager.cpp \
    GUI/Specialized/VerticalDropDown.cpp \
    GUI/GUI_Element.cpp \
    GUI/GUI_Interface.cpp \
    GUI/GUI_Manager.cpp
    WindowSystem/GameWindow.cpp \

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
    ECS/Core/systemtypes.h \
    inits.h \
    ECS/Systems/system_move.h \
    Resources/AudioManager.h \
    Resources/FontManager.h \
    Resources/ResourceManager.h \
    Resources/TextureManager.h \
    SharedContext.h \
    ThreadWorkers/FileLoader.h \
    ThreadWorkers/Worker.h \
    ECS/Systems/system_renderer.h \
    Map/tile.h \
    Map/map.h \
    Utilities/SimplexNoise.h \
    Map/mapgenerator.h \
    WindowSystem/Renderer.h \
    EventSystem/Binding.h \
    EventSystem/EventDetails.h \
    EventSystem/EventInfo.h \
    EventSystem/EventTypes.h \
    StateSystem/BaseState.h \
    StateSystem/StateDependent.h \
    StateSystem/StateManager.h \
    StateSystem/StateTypes.h \
    StateSystem/States/State_Loading.h \
    game.h \
    StateSystem/States/State_Game.h \
    EventSystem/EventManager.h \
    Utilities/FastNoise.h \
    GUI/Elements/GUI_CheckBox.h \
    GUI/Elements/GUI_DropDownMenu.h \
    GUI/Elements/GUI_Label.h \
    GUI/Elements/GUI_Scrollbar.h \
    GUI/Elements/GUI_Sprite.h \
    GUI/Elements/GUI_TextField.h \
    GUI/Specialized/FileManager.h \
    GUI/Specialized/VerticalDropDown.h \
    GUI/GUI_Element.h \
    GUI/GUI_Event.h \
    GUI/GUI_Interface.h \
    GUI/GUI_Manager.h \
    GUI/GUI_Style.h
    WindowSystem/GameWindow.h \
    Types/Bitmask.h

DISTFILES += \
    textures.cfg \
    media/maps/test.map \
    fonts.cfg \
    keys.cfg
