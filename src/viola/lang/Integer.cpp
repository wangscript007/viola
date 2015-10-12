/*
 * Integer.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "Integer.h"

Integer::Integer(int value) {
	this->i = value;
}

Integer::~Integer() {
	//noop
	//printf("deleted\n");
}

int Integer::get() {
	return this->i;
}

//Override
int Integer::hashCode() {
	return this->i;
}

//Override
bool Integer::equals(Object* obj) {
	return this->equals((Integer*) obj);
}

//Override
bool Integer::equals(Integer* obj) {
	return this->equals(obj->get());
}

//Override
bool Integer::equals(object obj) {
	return this->equals((Integer*) obj.get());
}

//Override
bool Integer::equals(int obj) {

	if (get() != obj) {
		return false;
	}

	return true;
}

//Override
string Integer::getClassName() {
	return "Integer";
}
