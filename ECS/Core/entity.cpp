#include "entity.h"
#include "Utilities/idgenerator.h"

Bitmask Entity::getMask() const
{
    return mask;
}

void Entity::setMask(const Bitmask &value)
{
    mask = value;
}

std::__cxx11::string Entity::getInfo()
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
            mask.ClearBit(c);
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
