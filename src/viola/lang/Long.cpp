/*
 * Long.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include <Long.h>

Long::Long(long value) {
	this->value = value;
}

Long::~Long() {
	//noop
}

//Override
string Long::getClassName() {
	return "Long";
}

//Override
int Long::hashCode() {
	return this->value;
}

//Override
string Long::toString() {
	string str("Long[");
	str.append(std::to_string(this->hashCode()));
	str.append("]");
	return str;
}
