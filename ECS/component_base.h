#ifndef COMPONENT_BASE_H
#define COMPONENT_BASE_H

#include <sstream>

enum ComponentType_t {
    drawable = 0,
    COUNT
};

class Component_Base{
public:
    Component_Base(const ComponentType_t& l_type): m_type(l_type) {}
    virtual ~Component_Base() {}

    ComponentType_t GetType() const { return m_type; }

    friend std::stringstream& operator >>(
        std::stringstream& l_stream, Component_Base& b)
    {
        b.ReadIn(l_stream);
        return l_stream;
    }

    virtual void ReadIn(std::stringstream& l_stream) = 0;
protected:
    ComponentType_t m_type;
};

#endif // COMPONENT_BASE_H
