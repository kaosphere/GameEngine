#include <iostream>
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
        Component_Position* pos = (*iter)->getComponent<Component_Position>(position);
        Component_Speed *sp = (*iter)->getComponent<Component_Speed>(speed);

        if(pos == NULL || sp == NULL) {
            return;
        }

        // Update position value with speed value
        pos->setX(pos->getX() + sp->getDx());
        pos->setY(pos->getY() + sp->getDy());

        std::cout << (*iter)->getEntityId() << " moved to " <<
                     pos->getX() << "," <<
                     pos->getY() << std::endl;
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
