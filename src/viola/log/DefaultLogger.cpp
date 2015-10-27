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

}

std::string DefaultLogger::getClassName() {
	return "DefaultLogger";
}

