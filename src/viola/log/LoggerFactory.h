/*
 * LoggerFactory.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_LOGGERFACTORY_H_
#define SRC_VIOLA_LOG_LOGGERFACTORY_H_

#include "Object.h"
#include "Logger.h"
#include "DefaultLogger.h"

class LoggerFactory: public Object {
public:
	LoggerFactory();
	~LoggerFactory();

	static std::shared_ptr<Logger> getLogger(std::string name) {
		std::shared_ptr<Logger> logger = std::make_shared<DefaultLogger>(name);
		return logger;
	}

};

#endif /* SRC_VIOLA_LOG_LOGGERFACTORY_H_ */
