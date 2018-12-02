#include "system_base.h"
#include "systemmanager.h"

System_Base::System_Base(const System& l_id, SystemManager* l_systemMgr)
    : m_id(l_id), m_systemManager(l_systemMgr) {}

System_Base::~System_Base() { Purge(); }

bool System_Base::AddEntity(const Entity& l_entity) {
    /*if (HasEntity(l_entity)) { return false; }
    m_entities.emplace_back(l_entity);
    return true;*/
}

bool System_Base::HasEntity(const Entity& l_entity) const {
    //return std::find(m_entities.begin(), m_entities.end(), l_entity) != m_entities.end();
}

bool System_Base::RemoveEntity(const Entity& l_entity) {
    /*auto entity = std::find_if(m_entities.begin(), m_entities.end(),
        [&l_entity](EntityId& id) { return id == l_entity; });
    if (entity == m_entities.end()) { return false; }
    m_entities.erase(entity);*/
    return true;
}

System System_Base::GetId() const { return m_id; }

/*bool System_Base::FitsRequirements(const Bitmask& l_bits) const {
    return std::find_if(m_requiredComponents.cbegin(), m_requiredComponents.cend(),
        [&l_bits](const Bitmask& b) { return b.Matches(l_bits, b.GetMask()); }) != m_requiredComponents.cend();
}*/

void System_Base::Purge() { m_entities.clear(); }
