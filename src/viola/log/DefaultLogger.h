/*
 * DefaultLogger.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_DEFAULTLOGGER_H_
#define SRC_VIOLA_LOG_DEFAULTLOGGER_H_

#include "Logger.h"

class DefaultLogger: public Logger {
public:
	DefaultLogger(std::string nmae);
	virtual ~DefaultLogger();

	//Override
	void info(std::string message);
	void debug(std::string message);
	void trace(std::string message);
	void warn(std::string message);
	void error(std::string message);

	std::string getClassName();

};

#endif /* SRC_VIOLA_LOG_DEFAULTLOGGER_H_ */
