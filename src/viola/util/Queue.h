/*
 * Queue.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_UTIL_QUEUE_H_
#define VIOLA_UTIL_QUEUE_H_

#include "Object.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class Queue: public Object {
public:
	Queue();
	~Queue();
};

#endif /* VIOLA_UTIL_QUEUE_H_ */
