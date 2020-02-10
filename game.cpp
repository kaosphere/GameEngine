#include "game.h"
#include "StateSystem/States/State_Game.h"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)),
    m_guiManager(m_window.GetEventManager(), &m_context)
{
    SetUpClasses();
    SetUpECS();
    SetUpStates();

    m_fontManager.RequireResource("Main");
    m_stateManager->SwitchTo(StateType::Game);
}

Game::~Game() { m_fontManager.ReleaseResource("Main"); }

sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }
GameWindow* Game::GetWindow() { return &m_window; }

void Game::Update() {
    m_window.Update();
    m_stateManager->Update(m_elapsed);
    m_guiManager.Update(m_elapsed.asSeconds());

    GUI_Event guiEvent;
    while (m_guiManager.PollEvent(guiEvent)) {
        m_window.GetEventManager()->HandleEvent(guiEvent);
    }
}

void Game::Render() {
    m_window.BeginDraw();
    // Render here.
    m_guiManager.Render(m_window.GetRenderWindow());
    m_stateManager->Draw();
    m_window.EndDraw();
}

void Game::LateUpdate() {
    m_stateManager->ProcessRequests();
    RestartClock();
}

void Game::SetUpClasses() {
    m_clock.restart();
    m_context.m_rand = &m_rand;
    srand(static_cast<unsigned int>(time(nullptr)));

    m_context.m_wind = &m_window;
    m_context.m_eventManager = m_window.GetEventManager();
    m_context.m_textureManager = &m_textureManager;
    m_context.m_fontManager = &m_fontManager;
    m_context.m_gameMap = &m_gameMap;
    m_context.m_systemManager = &m_systemManager;
    m_context.m_guiManager = &m_guiManager;

    m_stateManager = Utils::make_unique<StateManager>(&m_context);
    m_gameMap.setContext(&m_context);
}

void Game::SetUpECS() {
}

void Game::SetUpStates() {
    //m_stateManager->RegisterState<State_Intro>(StateType::Intro);
    //m_stateManager->RegisterState<State_MainMenu>(StateType::MainMenu);
    m_stateManager->RegisterState<State_Game>(StateType::Game);
}
