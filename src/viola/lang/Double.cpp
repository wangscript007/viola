/*
 * Double.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "Double.h"

Double::Double(double value) {
	this->value = value;
}

Double::~Double() {
	//noop
}

double Double::get() {
	return this->value;
}

unsigned long Double::doubleToLongBits() {
	union {
		double input;
		long output;
	} data;

	data.input = this->value;

	std::bitset<sizeof(double) * CHAR_BIT> bits(data.output);

	unsigned long ret = bits.to_ulong();

	return ret;
}

//Override
int Double::hashCode() {
	int ret = 0;

	unsigned long v = this->doubleToLongBits();

	ret = (int) (v ^ (v >> 32));
	return ret;
}

string Double::getClassName() {
	return "Double";
}

