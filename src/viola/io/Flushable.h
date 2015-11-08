/*
 * Flushable.h
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_IO_FLUSHABLE_H_
#define SRC_VIOLA_IO_FLUSHABLE_H_

#include "Object.h"
#include "IOException.h"

class Flushable: public Object {
public:
	Flushable();
	virtual ~Flushable();

	virtual void flush() throw (IOException);
};

#endif /* SRC_VIOLA_IO_FLUSHABLE_H_ */
