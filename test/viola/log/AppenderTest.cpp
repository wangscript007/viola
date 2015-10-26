/*
 * LoggerTest.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	_Appender fa = std::make_shared<FileAppender>();
	System::out::println(fa->getClassName());

	_Appender sa = std::make_shared<StandardOutAppender>();
	System::out::println(sa->getClassName());
	sa->doAppend("foobar");

	return 0;
}
