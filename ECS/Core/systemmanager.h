#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <vector>
#include <memory>
#include "entity.h"
#include "system_base.h"
#include "systemtypes.h"

class System_Base;

class SystemManager
{
public:
    SystemManager();
    ~SystemManager();

    template <typename S_type>
    void addSystem(const SystemType_t& t)
    {}

    template <typename S_type>
    void getSystem(const SystemType_t& t)
    {}

    bool removeSystem(const SystemType_t& t);

    bool registerEntity(std::shared_ptr<Entity>);
    bool removeEntity(const std::string& entityId);

    void purgeSystems();
    void purgeEntities();

    void update(float dt);

protected:
    std::vector<std::unique_ptr<System_Base>> m_systems;
};

#endif // SYSTEMMANAGER_H
