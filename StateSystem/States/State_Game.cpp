#include "State_Game.h"
#include "StateSystem/StateManager.h"
#include "WindowSystem/Window.h"
#include "StateSystem/States/State_Loading.h"
#include "ECS/Core/systemmanager.h"
//#include "Map/map.h"

State_Game::State_Game(StateManager* l_stateManager)
	: BaseState(l_stateManager) {}

State_Game::~State_Game() {}

void State_Game::OnCreate() {
	auto context = m_stateMgr->GetContext();

    EventManager* evMgr = context->m_eventManager;

    evMgr->AddCallback("Mouse_Wheel_Moved", &State_Game::mapMove, this);
    evMgr->AddCallback("Move_Map_Right", &State_Game::mapMove, this);
    evMgr->AddCallback("Move_Map_Left", &State_Game::mapMove, this);
    evMgr->AddCallback("Move_Map_Up", &State_Game::mapMove, this);
    evMgr->AddCallback("Move_Map_Down", &State_Game::mapMove, this);

	auto loading = m_stateMgr->GetState<State_Loading>(StateType::Loading);
    context->m_gameMap->AddFile(Utils::GetWorkingDirectory() + "media/maps/gen.map");
	loading->AddLoader(context->m_gameMap);
    loading->SetManualContinue(false);
}

void State_Game::OnDestroy() {
    //auto context = m_stateMgr->GetContext();
}

void State_Game::Update(const sf::Time& l_time) {
	auto context = m_stateMgr->GetContext();
	UpdateCamera();
    context->m_gameMap->update(l_time.asSeconds());
    context->m_systemManager->update(l_time.asSeconds());
}

void State_Game::UpdateCamera() {
}

void State_Game::Draw() {
    SharedContext *context = m_stateMgr->GetContext();
    context->m_gameMap->drawMap(context->m_wind->GetRenderWindow());

    //m_stateMgr->GetContext()->m_systemManager->Draw(m_stateMgr->GetContext()->m_wind, i);

}

void State_Game::mapMove(EventDetails *l_details)
{
    if(l_details->m_mouseWheelDelta > 0)
        m_view.zoom(1.f / 1.1);
    else if (l_details->m_mouseWheelDelta < 0)
        m_view.zoom(1.1);

    if (l_details->m_keyCode == sf::Keyboard::W)
    {
        m_view.move(0,-10);
    }
    if (l_details->m_keyCode == sf::Keyboard::S)
    {
        m_view.move(0,10);
    }
    if (l_details->m_keyCode == sf::Keyboard::A)
    {
        m_view.move(-10,0);
    }
    if (l_details->m_keyCode == sf::Keyboard::D)
    {
        m_view.move(10,0);
    }

    /*while (m_window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            m_window.close();

        if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    v->move(0,-10);
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    v->move(0,10);
                }
                if (event.key.code == sf::Keyboard::A)
                {
                    v->move(-10,0);
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    v->move(10,0);
                }
            }

        if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.delta > 0)
                v->zoom(1.f / 1.1);
            else if (event.mouseWheelScroll.delta < 0)
                v->zoom(1.1);
        }
    }
    m_window.setView(*v);*/
}

void State_Game::Activate() {
    SharedContext *context = m_stateMgr->GetContext();
    context->m_gameMap->sortMapTiles();
    context->m_gameMap->drawMap(context->m_wind->GetRenderWindow());
}

void State_Game::Deactivate() {}

