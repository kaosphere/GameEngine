#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <memory>
#include "component_base.h"
#include "Types/Bitmask.h"
#include "Utilities/idgenerator.h"

using ComponentPtr =std::unique_ptr<Component_Base>;

class Entity {

private:
    std::string entityId;
    Bitmask mask;
    std::vector<ComponentPtr> components;

    // Private copy constructor
    Entity(const Entity& e){}

public:
    Entity();
    ~Entity();

    std::string getEntityId() const;

    template <typename C_type>
    bool addComponent(const ComponentType_t &c)
    {
        // Add component if we don't have one of this type already
        if (!hasComponent(c) && c != _invalidComponentType) {
            C_type *ptr = new C_type;
            components.emplace_back(ptr);
            mask.TurnOnBit(c);
            return true;
        }
        return false;
    }

    bool removeComponent(const ComponentType_t& c);
    bool hasComponent(const ComponentType_t& c);
    Bitmask getMask() const;
    void setMask(const Bitmask &value);
    std::string getInfo();
};
#endif // ENTITY_H
