#include "action.h"


Action::Action(string name):m_name(name) {}


Action::~Action() {}

string Action::to_string() {
	return m_name;
}

string Action::getName() {
	return m_name;
}
