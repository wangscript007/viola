/*
 * Appender.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_APPENDER_H_
#define SRC_VIOLA_LOG_APPENDER_H_

#include "Object.h"
#include "Strings.h"
#include "System.h"

class Appender: public Object {

public:
	Appender();
	virtual ~Appender();

	void doAppend(std::string level, std::string message);

	virtual void append(std::string message);

	//Override
	virtual std::string getClassName();
};

#endif /* SRC_VIOLA_LOG_APPENDER_H_ */
