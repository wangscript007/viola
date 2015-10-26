/*
 * Appender.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_APPENDER_H_
#define SRC_VIOLA_LOG_APPENDER_H_

#include "Object.h"

class Appender:public Object {
public:
	Appender();
	virtual ~Appender();
};

#endif /* SRC_VIOLA_LOG_APPENDER_H_ */
