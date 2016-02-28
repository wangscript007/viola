/*
 * Logger.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "Logger.h"

Logger::Logger(std::string name) {
	this->name = name;
	this->level = 2;
}

Logger::~Logger() {
	list.clear();
}

void Logger::addAppender(std::shared_ptr<Appender> appender) {
	this->list.push_back(appender);
}

void Logger::appendAll(std::string level, std::string message) {
	std::list<std::shared_ptr<Appender> >::iterator it = list.begin();
	for (uint32_t i = 0; i < list.size(); i++) {
		std::shared_ptr<Appender> appender = *it;
		appender->doAppend(level, message);
	}
}

void Logger::detachAllAppender() {
	list.clear();
}

std::string Logger::getName() {
	return name;
}

uint32_t Logger::getLevel() {
	return level;
}
void Logger::setLevel(uint32_t level) {
	this->level = level;
}

bool Logger::isTraceEnabled() {
	if (level > 3) {
		return true;
	}
	return false;
}
bool Logger::isDebugEnabled() {
	if (level > 2) {
		return true;
	}
	return false;
}
bool Logger::isInfoEnabled() {
	if (level > 1) {
		return true;
	}
	return false;
}
bool Logger::isWarnEnabled() {
	if (level > 0) {
		return true;
	}
	return false;
}
bool Logger::isErrorEnabled() {
	if (level > -1) {
		return true;
	}
	return false;
}

void Logger::trace(std::string message) {
	if (!isTraceEnabled()) {
		return;
	}

	appendAll("TRACE", message);
}

void Logger::debug(std::string message) {
	if (!isDebugEnabled()) {
		return;
	}

	appendAll("DEBUG", message);
}

void Logger::info(std::string message) {
	if (!isInfoEnabled()) {
		return;
	}

	appendAll("INFO", message);
}

void Logger::warn(std::string message) {
	if (!isWarnEnabled()) {
		return;
	}

	appendAll("WARN", message);
}

void Logger::error(std::string message) {
	if (!isErrorEnabled()) {
		return;
	}

	appendAll("ERROR", message);
}



std::string Logger::getClassName() {
	return "Logger";
}

