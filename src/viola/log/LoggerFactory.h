/*
 * LoggerFactory.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "Logger.h"

class LoggerFactory: public Object {
public:
	LoggerFactory();
	~LoggerFactory();

	static std::shared_ptr<Logger> getLogger(std::string name) {
		std::shared_ptr<Logger> logger = std::make_shared<Logger>(name);
		return logger;
	}

};
