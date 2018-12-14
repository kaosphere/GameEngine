#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "StateSystem/BaseState.h"
#include "Map/map.h"
#include "EventSystem/EventManager.h"

#define MOVE_SPEED 20

class State_Game : public BaseState{
public:
	State_Game(StateManager* l_stateManager);
	~State_Game();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

    void mapMove(EventDetails *l_details);

private:
	void UpdateCamera();
    float m_zoomFactor;
    //int m_player;
};
