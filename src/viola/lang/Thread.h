/*
 * Thread.h
 *
 *  Created on: 2016/02/29
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Thread: public Object {
public:
	Thread();
	virtual ~Thread();

	std::string getClassName();
};
