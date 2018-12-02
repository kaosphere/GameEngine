#ifndef COMPONENT_BASE_H
#define COMPONENT_BASE_H

#include <sstream>
#include <string>
#include "componenttypes.h"

class Component_Base{
public:
    virtual ~Component_Base(){}
    ComponentType_t getType() const { return _mType;}
    virtual std::string getInfo() = 0;
protected:
    /// Default invalid component type
    static const ComponentType_t _mType = _invalidComponentType;
};

#endif // COMPONENT_BASE_H
