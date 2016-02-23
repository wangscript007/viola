/*
 * Long.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Long: public Object {
private:
	long value;
public:
	Long(long value);
	~Long();

	long get();

	bool equals(Long* obj);
	bool equals(std::shared_ptr<Object> obj);
	bool equals(long arg);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();
};
