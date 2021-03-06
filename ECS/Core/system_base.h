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

/**
 * @brief The System_Base class
 * A system is an object that handles entities having specific components.
 * For example : movement system that will move entities on a map.
 * An entity can be added to a system only if it complies with the system's
 * requirement mask.
 *
 * All systems are contained in the systemManager, who calls all systems for
 * update.
 *
 * On update, a system computes new values for all components, based on the elapsed
 * time since last call.
 */
class System_Base : public Observer{
public:
    System_Base();
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
    static const SystemType_t m_id = _invalidSystemType;
    Bitmask m_requiredComponents;
    EntityList m_entities;
};

#endif // SYSTEM_BASE_H
