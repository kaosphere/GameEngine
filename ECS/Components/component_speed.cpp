#include "component_speed.h"

Component_Speed::Component_Speed()
{

}

std::__cxx11::string Component_Speed::getInfo()
{
    std::string s;
    s += "Component Speed\n";
    s += "dX = " + std::to_string(dx) + "\n";
    s += "dY = " + std::to_string(dy) + "\n";
    return s;
}

