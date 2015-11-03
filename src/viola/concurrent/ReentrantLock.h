/*
 * ReentrantLock.h
 *
 *  Created on: 2015/10/28
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_CONCURRENT_REENTRANTLOCK_H_
#define SRC_VIOLA_CONCURRENT_REENTRANTLOCK_H_

#include "Object.h"

class ReentrantLock: public Object {
public:
	ReentrantLock();
	virtual ~ReentrantLock();
};

#endif /* SRC_VIOLA_CONCURRENT_REENTRANTLOCK_H_ */
