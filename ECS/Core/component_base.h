#ifndef COMPONENT_BASE_H
#define COMPONENT_BASE_H

#include <sstream>
#include <string>
#include "componenttypes.h"

/**
 * @brief The Component_Base class
 * A component is an element that can be added to any entity. It represents
 * a characteristic of this entity (ex : position, speed, strength, ...)
 */
class Component_Base{
public:
    Component_Base(){}
    Component_Base(ComponentType_t type):mComponentType(type){}
    virtual ~Component_Base(){}
    virtual ComponentType_t getType() const { return mComponentType;}
    virtual std::string getInfo() = 0;
protected:
    /// Default invalid component type
    ComponentType_t mComponentType = _invalidComponentType;
};

#endif // COMPONENT_BASE_H
