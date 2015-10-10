/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Entry.h"
#include "Integer.h"

Entry::Entry(Object key, Object value) {
	printf("Entry.className: <%s>\n", key.getClassName().c_str());
	this->key = std::make_shared<Object>(key);
	this->value = std::make_shared<Object>(value);
}

Entry::~Entry() {
}

Object* Entry::getKey() {
	printf("getKey.className: <%s>\n", key.get()->getClassName().c_str());
	return key.get();
}
Object* Entry::getValue() {
	return value.get();
}

//Override
int Entry::hashCode() {
	int keyHash = 0;
	if (this->key.get() != NULL) {
		keyHash = key.get()->hashCode();
	}

	int valueHash = 0;
	if (this->value.get() != NULL) {
		valueHash = value.get()->hashCode();
	}

	return keyHash ^ valueHash;
}

//Override
std::string Entry::getClassName() {
	return "Entry";
}
