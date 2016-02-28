/*
 * Date.h
 *
 *  Created on: 2015/10/28
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "System.h"

class Date: public Object {
private:
	uint64_t timestamp;
public:
	Date();
	Date(uint64_t timestamp);
	virtual ~Date();

	uint64_t getTime();
};
