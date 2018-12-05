#include "system_move.h"
#include "ECS/Components/component_position.h"
#include "ECS/Components/component_speed.h"

System_Move::System_Move()
{
    // Set required components
    m_requiredComponents.TurnOnBit((unsigned int)position);
    m_requiredComponents.TurnOnBit((unsigned int)speed);
}

void System_Move::update(float l_dT)
{
    for(auto iter = m_entities.begin(); iter != m_entities.end(); ++iter) {
        // Update position value with speed value
        (*iter)->getComponent<Component_Position>(position)->setX(
                   (*iter)->getComponent<Component_Position>(position)->getX() +
                   (*iter)->getComponent<Component_Speed>(speed)->getDx() );

        (*iter)->getComponent<Component_Position>(position)->setY(
                    (*iter)->getComponent<Component_Position>(position)->getY() +
                   (*iter)->getComponent<Component_Speed>(speed)->getDy() );
    }
}

void System_Move::handleEvent(const Entity &l_entity, const EntityEvent &l_event)
{

}

std::string System_Move::getInfo()
{

}

void System_Move::Notify(const Message& l_message)
{

}
