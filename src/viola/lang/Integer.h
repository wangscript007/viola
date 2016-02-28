/*
 * Integer.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Integer: public Object {
private:
	int32_t i;
public:
	//Integer(int value);
	Integer(int32_t value);
	~Integer();

	int32_t get();

	bool equals(Integer* obj);
	bool equals(std::shared_ptr<Object> obj);
	bool equals(int arg);

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};
