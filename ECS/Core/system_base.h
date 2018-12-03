#ifndef SYSTEM_BASE_H
#define SYSTEM_BASE_H

#include <memory>
#include "systemmanager.h"
#include "entity.h"
#include "EntityEvents.h"
#include "Observer/Observer.h"
#include "systemtypes.h"

using EntityList = std::vector<std::shared_ptr<Entity>>;

class SystemManager;
class System_Base : public Observer{
public:
    System_Base(const SystemType_t& l_id);
    virtual ~System_Base();

    bool addEntity(std::shared_ptr<Entity> l_entity);
    bool hasEntity(std::shared_ptr<Entity> l_entity) const;
    bool removeEntity(std::shared_ptr<Entity> l_entity);

    SystemType_t getId() const;
    virtual std::string getInfo() = 0;

    bool fitsRequirements(const Bitmask& l_bits) const;
    void purge();

    virtual void update(float l_dT) = 0;
    virtual void handleEvent(const Entity& l_entity, const EntityEvent& l_event) = 0;
protected:
    SystemType_t m_id;
    Bitmask m_requiredComponents;
    EntityList m_entities;
};

#endif // SYSTEM_BASE_H
