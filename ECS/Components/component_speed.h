#ifndef COMPONENT_SPEED_H
#define COMPONENT_SPEED_H

#include "ECS/Core/component_base.h"
#include "ECS/Core/componenttypes.h"

/**
 * @brief The Component_Speed class
 * The components represents the move speed of an entity on the map
 */
class Component_Speed : public Component_Base
{
public:
    Component_Speed();
    virtual ~Component_Speed(){}
    virtual ComponentType_t getType() const { return _mType;}
    virtual std::string getInfo();

    float getDx() const;
    void setDx(float value);

    float getDy() const;
    void setDy(float value);

protected:
    static const ComponentType_t Component_Base::_mType = speed;
    /**
     * @brief dx Move speed on x axis
     */
    float dx;

    /**
     * @brief dy Move speed on y axis
     */
    float dy;
};

#endif // COMPONENT_SPEED_H
