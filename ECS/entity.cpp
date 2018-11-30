#include "entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

unsigned int Entity::getEntityId() const
{
    return entityId;
}

void Entity::setEntityId(unsigned int value)
{
    entityId = value;
}
