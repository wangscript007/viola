/*
 * Object.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Object.h"

Object::Object() {
	//noop
}

Object::~Object() {
	//noop
}

int Object::hashCode() {
	return reinterpret_cast<uintptr_t>(this);
}

bool Object::equals(Object* obj) {
	if (obj == NULL) {
		return false;
	}

	if (hashCode() != obj->hashCode()) {
		return false;
	}

	return true;
}

std::string Object::getClassName() {
	return "Object";
}

std::string Object::toString() {
	std::string str(getClassName());
	str.append("[");
	str.append(std::to_string(this->hashCode()));
	str.append("]");
	return str;
}


