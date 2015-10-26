/*
 * LoggerTest.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	_Logger log = LoggerFactory::getLogger("LoggerTest");
	System::out::println(log->getName());
	System::out::println(log->getClassName());

	log->info("foobar");
	log->debug("foobar");
	log->trace("foobar");
	log->warn("foobar");
	log->error("foobar");

	return 0;
}
