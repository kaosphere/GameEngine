#ifndef GAME_H
#define GAME_H

#include "WindowSystem/GameWindow.h"
#include "GUI/GUI_Manager.h"
//#include "EventSystem/EventManager.h"
#include "StateSystem/StateManager.h"
#include "Resources/TextureManager.h"
#include "Utilities/RandomGenerator.h"
#include "Resources/FontManager.h"
//#include "Resources/AudioManager.h"
//#include "SoundSystem/SoundManager.h"
#include "Map/map.h"
#include "ECS/Core/systemmanager.h"

class Game{
public:
    Game();
    ~Game();

    void Update();
    void Render();
    void LateUpdate();

    sf::Time GetElapsed();

    GameWindow* GetWindow();
private:
    void SetUpClasses();
    void SetUpECS();
    void SetUpStates();
    void RestartClock();
    sf::Clock m_clock;
    sf::Time m_elapsed;
    SharedContext m_context;
    RandomGenerator m_rand;
    GameWindow m_window;
    TextureManager m_textureManager;
    FontManager m_fontManager;
    SystemManager m_systemManager;
    GUI_Manager m_guiManager;
    Map m_gameMap;
    std::unique_ptr<StateManager> m_stateManager;
};

#endif // GAME_H
