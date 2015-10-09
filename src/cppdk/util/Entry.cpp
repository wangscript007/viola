/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Entry.h"
#include "stdio.h"

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

//Override
int Entry::hashCode() {
	int keyHash = 0;
	if (this->key != NULL) {
		keyHash = this->key->hashCode();
	}

	int valueHash = 0;
	if (this->value != NULL) {
		valueHash = this->value->hashCode();
	}

	return keyHash ^ valueHash;
}

