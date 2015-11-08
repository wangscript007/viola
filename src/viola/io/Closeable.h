/*
 * Closeable.h
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_IO_CLOSEABLE_H_
#define SRC_VIOLA_IO_CLOSEABLE_H_

#include "Object.h"
#include "IOException.h"

class Closeable: public Object {
public:
	Closeable();
	virtual ~Closeable();

	virtual void close() throw (IOException);
};

#endif /* SRC_VIOLA_IO_CLOSEABLE_H_ */
