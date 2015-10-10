/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Entry.h"

Entry::Entry(object key, object value) {
	printf("Entry.className: <%s>\n", key.get()->getClassName().c_str());
	this->key = key;
	this->value = value;
}

Entry::~Entry() {
}

object Entry::getKey() {
	return key;
}
object Entry::getValue() {
	return value;
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
