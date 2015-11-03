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

Date::Date(long timestamp) {
	this->timestamp = timestamp;
}

Date::~Date() {

}

long Date::getTime() {
	return timestamp;
}
