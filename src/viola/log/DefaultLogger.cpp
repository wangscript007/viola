/*
 * DefaultLogger.cpp
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#include "DefaultLogger.h"

DefaultLogger::DefaultLogger(std::string name) :
		Logger(name) {

}

DefaultLogger::~DefaultLogger() {
	// TODO Auto-generated destructor stub
}

void DefaultLogger::info(std::string message) {

}
void DefaultLogger::debug(std::string message) {

}
void DefaultLogger::trace(std::string message) {

}
void DefaultLogger::warn(std::string message) {

}
void DefaultLogger::error(std::string message) {

}

std::string DefaultLogger::getClassName() {
	return "DefaultLogger";
}

