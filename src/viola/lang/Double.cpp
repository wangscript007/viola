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
bool Double::equals(Double* obj) {
	return this->equals(obj->get());
}

//Override
bool Double::equals(std::shared_ptr<Object> obj) {
	return this->equals((Double*) obj.get());
}

//Override
bool Double::equals(double obj) {

	if (get() == obj) {
		return true;
	}

	return false;
}

//Override
int Double::hashCode() {
	int ret = 0;

	unsigned long v = this->doubleToLongBits();

	ret = (int) (v ^ (v >> 32));
	return ret;
}
//Override
bool Double::equals(Object* obj) {
	return this->equals((Double*) obj);
}

//Override
std::string Double::getClassName() {
	return "Double";
}

//Override
std::string Double::toString() {
	return std::to_string(this->hashCode());
}
