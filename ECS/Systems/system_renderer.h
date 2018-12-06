#ifndef SYSTEM_RENDERER_H
#define SYSTEM_RENDERER_H

#include "ECS/Core/system_base.h"
#include "ECS/Core/systemtypes.h"

class System_Renderer : public System_Base
{
public:
    System_Renderer();

    /**
     * @brief update Implementation
     * @param l_dT Time delta from last iteration
     */
    virtual void update(float l_dT);

    /**
     * @brief handleEvent Event handler
     * @param l_entity
     * @param l_event
     */
    virtual void handleEvent(const Entity& l_entity, const EntityEvent& l_event);

    virtual std::string getInfo();

    virtual void Notify(const Message& l_message);

    void draw();

protected:
    static const SystemType_t System_Base::m_id = Renderer;
};

#endif // SYSTEM_RENDERER_H
