#include "systemmanager.h"

SystemManager::SystemManager()
{

}

bool SystemManager::removeSystem(const SystemType_t &t)
{

}

void SystemManager::update(float dt)
{
    for(auto& itr : m_systems) { itr->update(dt); }
}
