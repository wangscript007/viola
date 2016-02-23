/*
 * Logger.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#pragma once
#include <list>
#include "Object.h"
#include "Appender.h"

class Logger: public Object {
protected:
	std::string name;
	int level;
	std::list<std::shared_ptr<Appender>> list;
public:
	Logger(std::string name);
	virtual ~Logger();

	std::string getName();
	int getLevel();
	void setLevel(int level);

	void addAppender(std::shared_ptr<Appender> appender);
	void detachAllAppender();
	void appendAll(std::string level, std::string message);

	bool isTraceEnabled();
	bool isDebugEnabled();
	bool isInfoEnabled();
	bool isWarnEnabled();
	bool isErrorEnabled();

	void trace(std::string message); // 4
	void debug(std::string message); // 3
	void info(std::string message); // 2 default
	void warn(std::string message); // 1
	void error(std::string message); // 0

	//Override
	virtual std::string getClassName();

};
