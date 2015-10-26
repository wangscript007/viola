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
void Logger::info(std::string message) {

}
void Logger::debug(std::string message) {

}
void Logger::trace(std::string message) {

}
void Logger::warn(std::string message) {

}
void Logger::error(std::string message) {

}

std::string Logger::getClassName() {
	return "Logger";
}

