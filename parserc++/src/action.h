#pragma once


#ifndef ACTION_H
#define ACTION_H

#include <string> 

using namespace std;


class Action {
	public:
		Action(string name);
		virtual ~Action();
		string getName();
		string to_string();
	private:
		string m_name;
};

#endif // ACTION_H

