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

uint64_t Double::doubleToLongBits() {
	union {
		double input;
		int64_t output;
	} data;

	data.input = this->value;

	std::bitset<sizeof(double) * CHAR_BIT> bits(data.output);

	uint64_t ret = bits.to_ulong();

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
uint32_t Double::hashCode() {
	uint32_t ret = 0;

	uint64_t v = this->doubleToLongBits();

	ret = (uint32_t) (v ^ (v >> 32));
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
