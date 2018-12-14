#pragma once
#include "EventTypes.h"

struct EventInfo {
	EventInfo() : m_type(EventInfoType::Normal), m_code(0) {}
	EventInfo(int l_eventCode) : m_type(EventInfoType::Normal), m_code(l_eventCode) {}
	EventInfo(const EventInfoType& l_type) {
		m_type = l_type;
	}

	EventInfo(const EventInfo& l_rhs) { Move(l_rhs); }

	EventInfo& operator=(const EventInfo& l_rhs) {
		if (&l_rhs != this) { Move(l_rhs); }
		return *this;
	}

    ~EventInfo() {}
	union {
		int m_code;
	};
	
	EventInfoType m_type;
private:
	void Move(const EventInfo& l_rhs) {
		m_type = l_rhs.m_type;
		if (m_type == EventInfoType::Normal) { m_code = l_rhs.m_code; }
	}
};
