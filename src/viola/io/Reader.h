/*
 * Reader.h
 *
 *  Created on: 2016/03/07
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "Closeable.h"
#include "IOException.h"

class Reader: public Object, public Closeable {
public:
	Reader();
	virtual ~Reader();

	virtual int read() throw (IOException);
	virtual int read(char cbuf[]) throw (IOException);
	virtual int read(char cbuf[], int offset, int length) throw (IOException);

	// Override
	virtual void close() throw (IOException);

};
