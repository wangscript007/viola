/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "../../cpp/util/Entry.h"

#include "stdio.h"

Entry::Entry(Object* key, Object* value) {
	this->key = key;
	this->value = value;

	this->key->incrementReference();
	this->value->incrementReference();
}

Entry::~Entry() {
	Object::tryDelete(key);
	Object::tryDelete(value);
}

Object* Entry::getKey() {
	this->key->incrementReference();
	return this->key;
}
Object* Entry::getValue() {
	this->key->incrementReference();
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

