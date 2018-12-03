#ifndef COMPONENT_SPEED_H
#define COMPONENT_SPEED_H

#include "ECS/Core/component_base.h"
#include "ECS/Core/componenttypes.h"

class Component_Speed : public Component_Base
{
public:
    Component_Speed();
    virtual ~Component_Speed(){}
    virtual std::string getInfo();

    float getDx() const;
    void setDx(float value);

    float getDy() const;
    void setDy(float value);

protected:
    static const ComponentType_t Component_Base::_mType = speed;
    float dx;
    float dy;
};

#endif // COMPONENT_SPEED_H
