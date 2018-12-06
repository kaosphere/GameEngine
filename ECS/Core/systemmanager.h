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
    ~SystemManager(){}

    template <typename S_type>
    bool addSystem(const SystemType_t& t)
    {
        // Add system if we don't have one of this type already
        if (!hasSystem(t) && t != _invalidSystemType) {
            S_type *ptr = new S_type;
            m_systems.emplace_back(ptr);
            return true;
        }
        return false;
    }

    template <typename S_type>
    void getSystem(const SystemType_t& t)
    {}

    bool hasSystem(const SystemType_t& t);

    bool removeSystem(const SystemType_t& t);

    bool registerEntity(std::shared_ptr<Entity> e);
    bool removeEntity(std::shared_ptr<Entity> e);

    void purgeSystems();
    void purgeEntities();

    void update(float dt);
    void draw();

protected:
    std::vector<std::unique_ptr<System_Base>> m_systems;
};

#endif // SYSTEMMANAGER_H
