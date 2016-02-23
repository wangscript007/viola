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
	int i;
public:
	Integer(int value);
	~Integer();

	int get();

	bool equals(Integer* obj);
	bool equals(std::shared_ptr<Object> obj);
	bool equals(int arg);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};
