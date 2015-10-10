/*
 * Double.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include <Double.h>

Double::Double(double value) {
	this->value = value;
}

Double::~Double() {
	//noop
}

double Double::get() {
	return this->value;
}

//Override
int Double::hashCode() {
	int ret = 0;

	//TODO IEEE 754 floating-point "double format" bit layout.
	unsigned long v = 0;

	ret = (int) (v ^ (v >> 32));
	return ret;
}

string Double::getClassName() {
	return "Double";
}

