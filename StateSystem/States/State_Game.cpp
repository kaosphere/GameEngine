#include "State_Game.h"
#include "StateSystem/StateManager.h"
#include "WindowSystem/Window.h"
#include "StateSystem/States/State_Loading.h"
#include "ECS/Core/systemmanager.h"
#include "GUI/GUI_Manager.h"
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

    GUI_Manager* gui = context->m_guiManager;
    gui->LoadInterface("MapEditorTools.interface", "MapEditorTools");
    gui->GetInterface("MapEditorTools")->SetPosition(sf::Vector2f(250.f, 168.f));

    m_zoomFactor = 1.0;
}

void State_Game::OnDestroy() {
    auto context = m_stateMgr->GetContext();

    EventManager *evMgr = context->m_eventManager;
    evMgr->RemoveCallback(StateType::Game, "Mouse_Wheel_Moved");
    evMgr->RemoveCallback(StateType::Game, "Move_Map_Right");
    evMgr->RemoveCallback(StateType::Game, "Move_Map_Left");
    evMgr->RemoveCallback(StateType::Game, "Move_Map_Up");
    evMgr->RemoveCallback(StateType::Game, "Move_Map_Down");
}

void State_Game::Update(const sf::Time& l_time) {
	auto context = m_stateMgr->GetContext();
	UpdateCamera();
    context->m_gameMap->update(l_time.asSeconds());
    context->m_systemManager->update(l_time.asSeconds());
    std::cout << 1.0f/l_time.asSeconds() << std::endl;
}

void State_Game::UpdateCamera() {
}

void State_Game::Draw() {
    SharedContext *context = m_stateMgr->GetContext();

    context->m_gameMap->drawMap(context->m_wind->GetRenderWindow(), context->m_wind->GetViewSpace());

    //m_stateMgr->GetContext()->m_systemManager->Draw(m_stateMgr->GetContext()->m_wind, i);

}

void State_Game::mapMove(EventDetails *l_details)
{
    if(l_details->m_mouseWheelDelta > 0) {
        m_view.zoom(1.f / 1.1);
        m_zoomFactor /= 1.1;
    }
    else if (l_details->m_mouseWheelDelta < 0) {
        m_view.zoom(1.1);
        m_zoomFactor *= 1.1;
    }
    if (l_details->m_keyCode == sf::Keyboard::W)
    {
        m_view.move(0,-MOVE_SPEED * m_zoomFactor);
    }
    if (l_details->m_keyCode == sf::Keyboard::S)
    {
        m_view.move(0,MOVE_SPEED * m_zoomFactor);
    }
    if (l_details->m_keyCode == sf::Keyboard::A)
    {
        m_view.move(-MOVE_SPEED,0 * m_zoomFactor);
    }
    if (l_details->m_keyCode == sf::Keyboard::D)
    {
        m_view.move(MOVE_SPEED,0 * m_zoomFactor);
    }
    std::cout << "zoom factor = " << m_zoomFactor << std::endl;
}

void State_Game::Activate() {
    /*SharedContext *context = m_stateMgr->GetContext();
    context->m_gameMap->sortMapTiles();
    context->m_gameMap->drawMap(context->m_wind->GetRenderWindow(), context->m_wind->GetViewSpace());*/
}

void State_Game::Deactivate() {}

