#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <memory>
#include "component_base.h"
#include "Types/Bitmask.h"
#include "Utilities/idgenerator.h"

using ComponentPtr =std::shared_ptr<Component_Base>;

/**
 * @brief The Entity class
 * An entity is an object of the game. It can either be a graphic object (player, enemy,
 * building, background...) or be a non physical element (weather model, economic model,
 * random event generator...).
 * An entity is composed of one or several components. When a component is added to
 * an entity, a bit is set in the component mask.
 * When added to a system, an entity must comply with the requirement mask of components
 * of the system.
 */
class Entity {

private:
    /**
     * @brief entityId Unique identifier of the entity
     */
    std::string entityId;

    /**
     * @brief componentMask Bitmask representing all the components of the entity
     */
    Bitmask componentMask;

    /**
     * @brief components List of components of the entity
     */
    std::vector<ComponentPtr> components;

    /// Private copy constructor
    Entity(const Entity& e __attribute__((unused))){}

public:
    Entity();
    ~Entity();

    std::string getEntityId() const;

    /**
     *  @brief addComponent
     *
     * Add a component to the entity
     * @param c Component type to be added
     */
    template <typename C_type>
    bool addComponent(const ComponentType_t &c)
    {
        // Add component if we don't have one of this type already
        if (!hasComponent(c) && c != _invalidComponentType) {
            C_type *ptr = new C_type;
            components.emplace_back(ptr);
            componentMask.TurnOnBit(c);
            return true;
        }
        return false;
    }

    /**
     * @brief getComponent
     *
     * Gets component corresponding to the specified component type
     * @param c Component type
     */
    template <typename C_type>
    C_type* getComponent(const ComponentType_t& c)
    {
        for(auto iter = components.begin(); iter != components.end(); ++iter) {
            ComponentType_t t = ((C_type*)(iter->get()))->getType();
            if (t == c) {
                return (C_type*)iter->get();
            }
        }
        return NULL;
    }

    bool removeComponent(const ComponentType_t& c);
    bool hasComponent(const ComponentType_t& c);
    Bitmask getMask() const;
    void setMask(const Bitmask &value);
    std::string getInfo();
};
#endif // ENTITY_H
