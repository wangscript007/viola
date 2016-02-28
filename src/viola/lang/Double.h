/*
 * Double.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#pragma once
#include <bitset>
#include "Object.h"

class Double: public Object {
private:
	double value;

public:
	Double(double value);
	~Double();

	double get();
	uint64_t doubleToLongBits();

	bool equals(Double* obj);
	bool equals(std::shared_ptr<Object> obj);
	bool equals(double arg);

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};
