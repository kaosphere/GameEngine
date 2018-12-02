#ifndef SYSTEM_BASE_H
#define SYSTEM_BASE_H

#include "systemmanager.h"
#include "entity.h"
#include "EntityEvents.h"
#include "Observer/Observer.h"

using EntityList = std::vector<Entity>;
//using Requirements = std::vector<Bitmask>;

enum class System{
    Renderer = 0, Movement, Collision, Control, State, SheetAnimation, Sound, COUNT
};

class SystemManager;
class System_Base : public Observer{
public:
    System_Base(const System& l_id, SystemManager* l_systemMgr);
    virtual ~System_Base();

    bool AddEntity(const Entity& l_entity);
    bool HasEntity(const Entity& l_entity) const;
    bool RemoveEntity(const Entity& l_entity);

    System GetId() const;

    //bool FitsRequirements(const Bitmask& l_bits) const;
    void Purge();

    virtual void Update(float l_dT) = 0;
    virtual void HandleEvent(const Entity& l_entity, const EntityEvent& l_event) = 0;
protected:
    System m_id;
    //Requirements m_requiredComponents;
    EntityList m_entities;

    SystemManager* m_systemManager;
};

#endif // SYSTEM_BASE_H
