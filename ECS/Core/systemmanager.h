#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <vector>
#include <memory>
#include "system_base.h"
#include "systemtypes.h"

class System_Base;

class SystemManager
{
public:
    SystemManager();

    template <typename S_type>
    void addSystem(const SystemType_t& t)
    {}

    bool removeSystem(const SystemType_t& t);

    void update(float dt);

protected:
    std::vector<std::unique_ptr<System_Base>> m_systems;
};

#endif // SYSTEMMANAGER_H
