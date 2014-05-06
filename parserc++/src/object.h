#pragma once


#ifndef OBJECT_H
#define OBJECT_H
 
#include "member.h"


class Object : public Member {
	public:
		Object(string name, vector<Type*> types);
		Object();
		void addTypes(vector<Type*> types);
		virtual string to_string();
};

#endif // OBJECT_H

