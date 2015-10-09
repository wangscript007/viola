/*
 * Object.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "../../cpp/lang/Object.h"

Object::Object() {
	//noop
}

Object::~Object() {
	//noop
}

void Object::incrementReference() {
	refCount++;
}

bool Object::decrementReference() {
	refCount--;

	if (refCount == 0) {
		return true;
	}
	return false;
}

int Object::getReference() {
	return refCount;
}

int Object::hashCode() {
	return 0;
}
