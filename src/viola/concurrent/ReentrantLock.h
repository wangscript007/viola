/*
 * ReentrantLock.h
 *
 *  Created on: 2015/10/28
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class ReentrantLock: public Object {
public:
	ReentrantLock();
	virtual ~ReentrantLock();
};
