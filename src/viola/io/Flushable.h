/*
 * Flushable.h
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "IOException.h"

class Flushable: public Object {
public:
	Flushable();
	virtual ~Flushable();

	virtual void flush() throw (IOException);
};

