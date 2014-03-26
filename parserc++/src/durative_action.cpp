#include "durative_action.h"


DurativeAction::DurativeAction(string name):Action(name) {}


DurativeAction::~DurativeAction() {}

void DurativeAction::addParameters(Variable * parameter) {
	m_parameters.push_back(parameter);
}

void DurativeAction::addCondition(Attribute att ,Fluent *fluent) {	
	m_preconditions.push_back(make_pair(att,fluent));
}

void DurativeAction::addEffect(Attribute att ,Fluent *fluent) {	
	m_effects.push_back(make_pair(att,fluent));
}

void DurativeAction::addDuration(float duration){
	m_duration=duration;
}

bool DurativeAction::isVariable(string name){
	for(vector<Variable *>::iterator it= m_parameters.begin();it != m_parameters.end();++it){
		if (((*it)->getName())==name) return true;
	}
	return false;
}

Variable *DurativeAction::getVariable(string name){
	for(vector<Variable *>::iterator it= m_parameters.begin();it != m_parameters.end();++it){
		if (((*it)->getName())==name) return (*it);
	}
}
