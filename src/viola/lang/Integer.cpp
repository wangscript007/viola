/*
 * Integer.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "Integer.h"

//Integer::Integer(int value) {
//	this->i = value;
//}

Integer::Integer(int32_t value) {
	this->i = value;
}

Integer::~Integer() {
	//noop
	//printf("deleted\n");
}

int32_t Integer::get() {
	return this->i;
}

//Override
bool Integer::equals(Integer* obj) {
	return this->equals(obj->get());
}

//Override
bool Integer::equals(std::shared_ptr<Object> obj) {
	return this->equals((Integer*) obj.get());
}

//Override
bool Integer::equals(int obj) {

	if (get() == obj) {
		return true;
	}

	return false;
}

//Override
uint32_t Integer::hashCode() {
	return this->i;
}

//Override
bool Integer::equals(Object* obj) {
	return this->equals((Integer*) obj);
}

//Override
std::string Integer::getClassName() {
	return "Integer";
}

//Override
std::string Integer::toString() {
	return std::to_string(this->hashCode());
}
