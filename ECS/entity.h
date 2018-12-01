#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>
#include "component_base.h"

using ComponentPtr =std::shared_ptr<Component_Base>;

class Entity {

private:
    unsigned int entityId;
    unsigned int bitmask;
    std::vector<ComponentPtr> components;

public:
    Entity();
    ~Entity();

    unsigned int getEntityId() const;
    void setEntityId(unsigned int value);
};
#endif // ENTITY_H
