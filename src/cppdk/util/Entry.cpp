/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Entry.h"

Entry::Entry(Object* key, Object* value) {
	this->key = key;
	this->value = value;
}

Entry::~Entry() {
}

Object* Entry::getKey() {
	return this->key;
}
Object* Entry::getValue() {
	return this->value;
}

int Entry::hashCode() {
	return 0;
}

