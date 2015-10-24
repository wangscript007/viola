/*
 * LoggerTest.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	_Logger logger = LoggerFactory::getLogger("LoggerTest");
	System::out::println(logger->getName());

	return 0;
}
