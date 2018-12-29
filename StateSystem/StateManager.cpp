#include "StateManager.h"
#include "StateDependent.h"
#include "States/State_Loading.h"
#include "../WindowSystem/Window.h"
#include "../GUI/GUI_Manager.h"

StateManager::StateManager(SharedContext* l_shared)
	: m_shared(l_shared)
{
	RegisterState<State_Loading>(StateType::Loading);
	CreateState(StateType::Loading);
	m_loading = static_cast<State_Loading*>(m_states.back().second.get());
}

StateManager::~StateManager() {
	for (auto &itr : m_states) { itr.second->OnDestroy(); }
}

void StateManager::Update(const sf::Time& l_time) {
	if (m_states.empty()) { return; }
	if (m_states.back().second->IsTranscendent() && m_states.size() > 1) {
		auto itr = m_states.end();
		while (itr != m_states.begin()) {
			if (itr != m_states.end()) {
				if (!itr->second->IsTranscendent()) {
					break;
				}
			}
			--itr;
		}
		for (; itr != m_states.end(); ++itr) { itr->second->Update(l_time); }
	} else {
		m_states.back().second->Update(l_time);
	}
}

void StateManager::Draw() {
    // If no state, return
	if (m_states.empty()) { return; }

    // If current state is transparent, iterate on states until we find a non transparent one
    // Then start to draw states from begin to end
	if(m_states.back().second->IsTransparent() && m_states.size() > 1) {
		auto itr = m_states.end();
		while(itr != m_states.begin()) {
			if(itr != m_states.end()) {
				if(!itr->second->IsTransparent()) {
					break;
				}
			}
			--itr;
		}
		for(; itr != m_states.end(); ++itr) {
			m_shared->m_wind->GetRenderWindow()->setView(itr->second->GetView());
			itr->second->Draw();
		}
	} else {
		m_shared->m_wind->GetRenderWindow()->setView(m_states.back().second->GetView());
		m_states.back().second->Draw();
	}
}

SharedContext* StateManager::GetContext() { return m_shared; }

bool StateManager::HasState(const StateType& l_type) const {
    for (auto itr = m_states.begin(); itr != m_states.end(); ++itr)
	{
		if (itr->first == l_type) {
			auto removed = std::find(m_toRemove.begin(), m_toRemove.end(), l_type);
			if (removed == m_toRemove.end()) { return true; }
			return false;
		}
	}
	return false;
}

StateType StateManager::GetCurrentStateType() const {
	if (m_states.empty()) { return static_cast<StateType>(0); }
	return m_states.back().first;
}

// Get state before the last one
StateType StateManager::GetNextToLast() const {
	if (m_states.empty()) { return static_cast<StateType>(0); }
	if (m_states.size() == 1) { return m_states.back().first; }
	return (m_states.end() - 2)->first;
}

void StateManager::ProcessRequests() {
	while (m_toRemove.begin() != m_toRemove.end()) {
		RemoveState(*m_toRemove.begin());
		m_toRemove.erase(m_toRemove.begin());
	}
}

void StateManager::SetGlobalState(const StateType& l_type) {
	for (auto& dependent : m_dependents) { dependent->ChangeState(l_type); }
}

void StateManager::SwitchTo(const StateType& l_type) {
    // If we are already in the state, return
	if (!m_states.empty() && m_states.back().first == l_type) { return; }

	SetGlobalState(l_type);
	for (auto itr = m_states.begin(); itr != m_states.end(); ++itr)
	{
		if (itr->first != l_type) { continue; }

        // Coming here, we found the next state, deactivate current one
		m_states.back().second->Deactivate();

        // Store new state in temp variables
		StateType tmp_type = itr->first;
		std::unique_ptr<BaseState> tmp_state = std::move(itr->second);

        // Erase it from the list
		m_states.erase(itr);
        // Activate it
		tmp_state->Activate();
		auto& view = tmp_state->GetView();

        // Put new state at the end of the list
		m_states.emplace_back(tmp_type, std::move(tmp_state));
        // Set the new view
		m_shared->m_wind->GetRenderWindow()->setView(view);

        // Transfer to loading state
		if (l_type == StateType::Loading) { return; }
		if (m_loading->HasWork()) { SwitchTo(StateType::Loading); }
		return;
	}

	// State with l_type wasn't found.
    // Deactivate previous one
	if (!m_states.empty()) { m_states.back().second->Deactivate(); }
    // Create requested state
	CreateState(l_type);
    // Activate it
	m_states.back().second->Activate();
    // Set the view
	m_shared->m_wind->GetRenderWindow()->setView(m_states.back().second->GetView());
	if (l_type == StateType::Loading) { return; }
	if (m_loading->HasWork()) { SwitchTo(StateType::Loading); }
}

void StateManager::Remove(const StateType& l_type) {
	for (auto itr = m_states.begin(); itr != m_states.end(); ++itr) {
		if (itr->first != l_type) { continue; }
		itr->second->OnDestroy();
		m_toRemove.push_back(l_type);
		for (auto& dependent : m_dependents) { dependent->RemoveState(l_type); }
	}
}

// Private methods.

void StateManager::CreateState(const StateType& l_type) {
	auto newState = m_stateFactory.find(l_type);
	if (newState == m_stateFactory.end()) { return; }
	std::unique_ptr<BaseState> state(newState->second());
	state->m_view = m_shared->m_wind->GetRenderWindow()->getDefaultView();
	m_states.emplace_back(l_type, std::move(state));
	m_states.back().second->OnCreate();
}

// Removes state with specified type
void StateManager::RemoveState(const StateType& l_type) {
	for (auto itr = m_states.begin(); itr != m_states.end(); ++itr)
	{
		if (itr->first != l_type) { continue; }
		m_states.erase(itr);
		return;
	}
}

void StateManager::AddDependent(StateDependent* l_dependent) {
	m_dependents.emplace_back(l_dependent);
}

void StateManager::RemoveDependent(StateDependent* l_dependent) {
	m_dependents.erase(std::find_if(m_dependents.begin(), m_dependents.end(), 
		[l_dependent](StateDependent* l_itr) { return l_itr == l_dependent; }
	));
}
