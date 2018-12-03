#include "component_position.h"

Component_Position::Component_Position()
{

}

std::__cxx11::string Component_Position::getInfo()
{
    std::string s;
    s += "Component Position\n";
    s += "X = " + std::to_string(x) + "\n";
    s += "Y = " + std::to_string(y) + "\n";
    return s;
}

float Component_Position::getX() const
{
    return x;
}

void Component_Position::setX(float value)
{
    x = value;
}

float Component_Position::getY() const
{
    return y;
}

void Component_Position::setY(float value)
{
    y = value;
}

