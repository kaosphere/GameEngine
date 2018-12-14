#pragma once
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <SFML/System/Time.hpp>
#include "StateTypes.h"
#include "../SharedContext.h"

class BaseState;
class StateDependent;
class State_Loading;

// State container.
using StateContainer = std::vector<std::pair<StateType, std::unique_ptr<BaseState>>>;
// Type container.
using TypeContainer = std::vector<StateType>;
// State factory.
using StateFactory = std::map<StateType, std::function<BaseState*(void)>>;
using StateDependents = std::vector< StateDependent* >;

class StateManager{
public:
	StateManager(SharedContext* l_shared);
	~StateManager();

	void Update(const sf::Time& l_time);
	void Draw();

	void ProcessRequests();

	SharedContext* GetContext();
	bool HasState(const StateType& l_type) const;
	StateType GetCurrentStateType() const;
	StateType GetNextToLast() const;
	void SwitchTo(const StateType& l_type);
	void Remove(const StateType& l_type);

    // Gets Pointer from state given the type of it
	template<class T>
	T* GetState(const StateType& l_type) {
		for (auto itr = m_states.begin(); itr != m_states.end(); ++itr) {
            // If the type of the state is not the good one, next item
			if (itr->first != l_type) { continue; }
            // Coming here, we found the right state, return it
			return static_cast<T*>(itr->second.get());
		}
		return nullptr;
	}

    // Adds a state type to the state factory
	template<class T>
	void RegisterState(const StateType& l_type) {
		m_stateFactory[l_type] = [this]() -> BaseState* { return new T(this); };
	}

	void AddDependent(StateDependent* l_dependent);
	void RemoveDependent(StateDependent* l_dependent);
private:
	// Methods.
	void SetGlobalState(const StateType& l_type);
	void CreateState(const StateType& l_type);
	void RemoveState(const StateType& l_type);

	// Members.
	SharedContext* m_shared;
	State_Loading* m_loading;
	StateContainer m_states;
	StateDependents m_dependents;
	TypeContainer m_toRemove;
	StateFactory m_stateFactory;
};
