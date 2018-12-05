#ifndef SYSTEM_MOVE_H
#define SYSTEM_MOVE_H

#include "ECS/Core/system_base.h"
#include "ECS/Core/systemtypes.h"

class System_Move : public System_Base
{
public:
    System_Move();

    /**
     * @brief update Implementation for system Movement
     * @param l_dT Time delta from last iteration used to calculate movement
     */
    virtual void update(float l_dT);

    /**
     * @brief handleEvent Event handler for movement system
     * @param l_entity
     * @param l_event
     */
    virtual void handleEvent(const Entity& l_entity, const EntityEvent& l_event);

    virtual std::string getInfo();

    virtual void Notify(const Message& l_message);

protected:
    static const SystemType_t System_Base::m_id = Movement;
};

#endif // SYSTEM_MOVE_H
