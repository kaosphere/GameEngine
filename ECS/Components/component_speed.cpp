#include "component_speed.h"

Component_Speed::Component_Speed()
{
    dx = 1;
    dy = 1;
}

std::__cxx11::string Component_Speed::getInfo()
{
    std::string s;
    s += "Component Speed\n";
    s += "dX = " + std::to_string(dx) + "\n";
    s += "dY = " + std::to_string(dy) + "\n";
    return s;
}

float Component_Speed::getDx() const
{
    return dx;
}

void Component_Speed::setDx(float value)
{
    dx = value;
}

float Component_Speed::getDy() const
{
    return dy;
}

void Component_Speed::setDy(float value)
{
    dy = value;
}

