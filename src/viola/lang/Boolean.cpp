/*
 * Boolean.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "Boolean.h"

Boolean::Boolean(bool tof) {
	value = tof;
}

Boolean::~Boolean() {
}

bool Boolean::get() {
	return value;
}

bool Boolean::equals(Boolean* obj) {
	return equals(obj->get());
}
bool Boolean::equals(std::shared_ptr<Boolean> obj) {
	return equals(obj.get());
}
bool Boolean::equals(bool arg) {
	if (value == arg) {
		return true;
	}
	return false;
}

//Override
uint32_t Boolean::hashCode() {
	return value;
}
bool Boolean::equals(Object* obj) {
	return this->equals((Boolean*) obj);
}
std::string Boolean::getClassName() {
	return "Boolean";
}
std::string Boolean::toString() {
	return std::to_string(value);
}
