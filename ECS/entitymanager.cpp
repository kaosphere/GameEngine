#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::addEntity(EntityPtr entity)
{
    entities[entity->getEntityId()] = entity;
}

