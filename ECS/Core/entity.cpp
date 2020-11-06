#include "entity.h"
#include "Utilities/idgenerator.h"

Bitmask Entity::getMask() const
{
    return componentMask;
}

void Entity::setMask(const Bitmask &value)
{
    componentMask = value;
}

std::string Entity::getInfo()
{
    std::string str;
    str += "Entity ID : " + entityId + "\n";
    str += "Components : \n";
    for(auto iter = components.begin(); iter != components.end(); ++iter) {
        str += (*iter)->getInfo();
    }
    return str;
}

Entity::Entity()
{
    entityId = IdGenerator::generateRandomID();
}

Entity::~Entity()
{
}

std::string Entity::getEntityId() const
{
    return entityId;
}

bool Entity::removeComponent(const ComponentType_t &c)
{
    for(auto iter = components.begin(); iter != components.end(); ++iter) {
        if ((*iter)->getType() == c) {
            components.erase(iter);
            componentMask.ClearBit(c);
            return true;
        }
    }
    return false;
}

bool Entity::hasComponent(const ComponentType_t &c)
{
    for(auto iter = components.begin(); iter != components.end(); ++iter) {
        if ((*iter)->getType() == c) return true;
    }
    return false;
}
