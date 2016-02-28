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
#include <stdint.h>

class Object {

public:
	Object();
	virtual ~Object();

	virtual uint32_t hashCode();
	virtual bool equals(Object* obj);
	virtual std::string getClassName();
	virtual std::string toString();
};
