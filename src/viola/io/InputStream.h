/*
 * InputStream.h
 *
 *  Created on: 2016/03/08
 *      Author: tsubaki
 */

#pragma once
#include "Closeable.h"

class InputStream: public Closeable {
public:
	InputStream();
	virtual ~InputStream();

	//Override
	virtual void close() throw (IOException);

};

