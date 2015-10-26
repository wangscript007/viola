/*
 * Logger.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_LOGGER_H_
#define SRC_VIOLA_LOG_LOGGER_H_

#include "Object.h"

class Logger: public Object {
protected:
	std::string name;
public:
	Logger(std::string name);
	virtual ~Logger();

	std::string getName();

	virtual void info(std::string message);
	virtual void debug(std::string message);
	virtual void trace(std::string message);
	virtual void warn(std::string message);
	virtual void error(std::string message);

	//Override
	virtual std::string getClassName();
};

#endif /* SRC_VIOLA_LOG_LOGGER_H_ */
