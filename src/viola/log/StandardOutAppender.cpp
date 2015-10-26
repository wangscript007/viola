/*
 * StandartOutAppender.cpp
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#include "StandardOutAppender.h"

StandardOutAppender::StandardOutAppender() {
	// TODO Auto-generated constructor stub

}

StandardOutAppender::~StandardOutAppender() {
	// TODO Auto-generated destructor stub
}

//Override
void StandardOutAppender::append(std::string message) {
	System::out::println(message);
}
//Override
std::string StandardOutAppender::getClassName() {
	return "StandardOutAppender";
}
