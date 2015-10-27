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
	System::out::println(log->getLevel());
	System::out::println(log->isTraceEnabled());
	System::out::println(log->isDebugEnabled());
	System::out::println(log->isInfoEnabled());
	System::out::println(log->isWarnEnabled());
	System::out::println(log->isErrorEnabled());

	_Appender sa = std::make_shared<StandardOutAppender>();
	System::out::println(sa->getClassName());
	log->addAppender(sa);

	log->trace("trace log");
	log->debug("debug log");
	log->info("info log");
	log->warn("warn log");
	log->error("error log");

	return 0;
}
