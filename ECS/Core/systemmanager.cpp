#include "systemmanager.h"
#include "ECS/Systems/system_renderer.h"
#include <iostream>

SystemManager::SystemManager()
{

}

bool SystemManager::hasSystem(const SystemType_t &t)
{
    for(auto iter = m_systems.begin(); iter != m_systems.end(); ++iter) {
        if ((*iter)->getId() == t) {
            return true;
        }
    }
    return false;
}

bool SystemManager::removeSystem(const SystemType_t &t)
{
    /*for(auto& itr : m_systems) {
        if (itr->getId() == t) {
            m_systems.erase(itr);
            return true;
        }
    }
    return false;*/
    for(auto iter = m_systems.begin(); iter != m_systems.end(); ++iter) {
        if ((*iter)->getId() == t) {
            m_systems.erase(iter);
            return true;
        }
    }
    return false;
}

bool SystemManager::registerEntity(std::shared_ptr<Entity> e)
{
    // Add entity to all systems who have matched requirements
    for(auto& itr : m_systems) {
        if (itr->fitsRequirements(e->getMask())) {
            itr->addEntity(e);
            std::cout << "entity " << e->getEntityId() << " was added to system " << itr->getId() << std::endl;
            return true;
        }
    }
    return false;
}

bool SystemManager::removeEntity(std::shared_ptr<Entity> e)
{
    for(auto& itr : m_systems) {
        if(itr->hasEntity(e)) {
            itr->removeEntity(e);
            return true;
        }
    }
    return false;
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

void SystemManager::draw()
{
    // Get render system and draw
    for(auto& itr : m_systems) {
        if(itr->getId() == Renderer) {
            System_Renderer *renderer = dynamic_cast<System_Renderer*>(itr.get());
            renderer->draw();
        }
    }
}
