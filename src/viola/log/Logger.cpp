/*
 * Logger.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "Logger.h"

Logger::Logger(std::string name) {
	this->name = name;
}

Logger::~Logger() {

}

std::string Logger::getName() {
	return name;
}
