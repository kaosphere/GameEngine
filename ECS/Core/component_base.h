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
    virtual ~Component_Base(){}
    virtual ComponentType_t getType() const { return _mType;}
    virtual std::string getInfo() = 0;
protected:
    /// Default invalid component type
    static const ComponentType_t _mType = _invalidComponentType;
};

#endif // COMPONENT_BASE_H
