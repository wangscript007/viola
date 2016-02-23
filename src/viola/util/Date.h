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
	long timestamp;
public:
	Date();
	Date(long timestamp);
	virtual ~Date();

	long getTime();
};
