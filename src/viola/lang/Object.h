/*
 * Object.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */


#pragma once
#include <string>
#include <memory>
#include <limits.h>

class Object {

public:
	Object();
	virtual ~Object();

	virtual int hashCode();
	virtual bool equals(Object* obj);
	virtual std::string getClassName();
	virtual std::string toString();
};
