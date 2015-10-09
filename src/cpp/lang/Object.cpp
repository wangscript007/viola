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

Object* Object::incrementReference() {
	refCount++;
//	printf("refCount.inc: <%d>\n", refCount);
	return this;
}

bool Object::decrementReference() {
	refCount--;
//	printf("refCount.dec: <%d>\n", refCount);
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

std::string Object::getClassName() {
	return "Object";
}
