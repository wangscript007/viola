/*
 * Appender.cpp
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#include "Appender.h"

Appender::Appender() {
	// TODO Auto-generated constructor stub

}

Appender::~Appender() {
	// TODO Auto-generated destructor stub
}

void Appender::append(std::string message) {

}

void Appender::doAppend(std::string level, std::string message) {
	std::string str;
	str.append("2015/10/26 21:48:10 ");
	str.append("[" + level + "] ");
	str.append(message);

	append(str);
}

//Override
std::string Appender::getClassName() {
	return "Appender";
}
