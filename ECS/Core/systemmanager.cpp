#include "systemmanager.h"

SystemManager::SystemManager()
{

}

bool SystemManager::removeSystem(const SystemType_t &t)
{

}

bool SystemManager::registerEntity(std::shared_ptr<Entity>)
{

}

bool SystemManager::removeEntity(const std::string &entityId)
{

}

void SystemManager::purgeSystems()
{
    purgeEntities();
    m_systems.clear();
}

void SystemManager::purgeEntities()
{
    for(auto& itr : m_systems) { itr->purge(); }
}

void SystemManager::update(float dt)
{
    for(auto& itr : m_systems) { itr->update(dt); }
}
