/*
 * Date.cpp
 *
 *  Created on: 2015/10/28
 *      Author: tsubaki
 */

#include "Date.h"

Date::Date() {
	this->timestamp = System::currentTimemillis();
}

Date::Date(uint64_t timestamp) {
	this->timestamp = timestamp;
}

Date::~Date() {

}

uint64_t Date::getTime() {
	return timestamp;
}
