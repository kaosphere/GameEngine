#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <map>
#include <memory>
#include "entity.h"

using EntityPtr = std::unique_ptr<Entity>;
using EntityId = unsigned int;

class EntityManager
{
public:
    EntityManager();
    int addEntity(const std::string& l_entityFile);
    //void addEntity(EntityPtr entity){entities[entity->getEntityId()] = &entity;}
    bool hasEntity(EntityId id){return (entities.find(id) == entities.end() ? false : true);}
    void removeEntity(EntityId id){entities.erase(id);}
    void addComponent(const Entity &id, const ComponentType_t& c);
    bool removeComponent(const Entity &id, const ComponentType_t& c);
    bool hasComponent(const Entity &id, const ComponentType_t& c);


private:
    // Add system manager and texture manager pointers
    std::map<EntityId, EntityPtr> entities;
};

#endif // ENTITYMANAGER_H
