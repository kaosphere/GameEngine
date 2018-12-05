#include <algorithm>
#include "system_base.h"
#include "systemmanager.h"

System_Base::System_Base(){}

System_Base::~System_Base() { purge(); }

bool System_Base::addEntity(std::shared_ptr<Entity> l_entity) {
    if (hasEntity(l_entity)) { return false; }
    m_entities.emplace_back(l_entity);
    return true;
}

bool System_Base::hasEntity(std::shared_ptr<Entity> l_entity) const {
    return std::find(m_entities.begin(), m_entities.end(), l_entity) != m_entities.end();
}

bool System_Base::removeEntity(std::shared_ptr<Entity> l_entity) {
    auto p = std::find(m_entities.begin(), m_entities.end(), l_entity);
    if (p != m_entities.end()) {
        m_entities.erase(p);
        return true;
    }
    return false;
}

SystemType_t System_Base::getId() const { return m_id; }

bool System_Base::fitsRequirements(const Bitmask& l_bits) const {
    return m_requiredComponents.Matches(l_bits, m_requiredComponents.GetMask());
}

void System_Base::purge() { m_entities.clear(); }
