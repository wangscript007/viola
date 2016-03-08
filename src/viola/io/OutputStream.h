/*
 * OutputStream.h
 *
 *  Created on: 2016/03/08
 *      Author: tsubaki
 */

#pragma once
#include "Closeable.h"
#include "Flushable.h"

class OutputStream: public Closeable, public Flushable {
public:
	OutputStream();
	virtual ~OutputStream();

	//Override
	virtual void close() throw (IOException);
	virtual void flush() throw (IOException);
};
