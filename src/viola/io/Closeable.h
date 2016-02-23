/*
 * Closeable.h
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "IOException.h"

class Closeable: public Object {
public:
	Closeable();
	virtual ~Closeable();

	virtual void close() throw (IOException);
};
