/*
 * Logger.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_LOGGER_H_
#define SRC_VIOLA_LOG_LOGGER_H_

#include "Object.h"

class Logger {
public:
	Logger(std::string name);
	virtual ~Logger();

	void info(std::string message);
	void debug(std::string message);
	void trace(std::string message);
	void warn(std::string message);
	void error(std::string message);
};

#endif /* SRC_VIOLA_LOG_LOGGER_H_ */
