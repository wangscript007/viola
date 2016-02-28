/*
 * Boolean.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Boolean: public Object {
private:
	bool value;
public:
	Boolean(bool tof);
	~Boolean();

	bool get();

	bool equals(Boolean* obj);
	bool equals(std::shared_ptr<Boolean> obj);
	bool equals(bool arg);

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();
};
