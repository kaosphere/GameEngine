#ifndef COMPONENT_POSITION_H
#define COMPONENT_POSITION_H

#include <string>
#include "ECS/Core/component_base.h"
#include "ECS/Core/componenttypes.h"

class Component_Position : public Component_Base
{
public:
    Component_Position();
    virtual ~Component_Position(){}
    virtual ComponentType_t getType() const { return _mType;}
    virtual std::string getInfo();

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

protected:
    static const ComponentType_t Component_Base::_mType = position;
    float x;
    float y;
};

#endif // COMPONENT_POSITION_H
