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

	this->key->incrementReference();
	this->value->incrementReference();
}

Entry::~Entry() {
	Object::tryDelete(key);
	Object::tryDelete(value);
}

Object* Entry::getKey() {
	return this->key->incrementReference();
}
Object* Entry::getValue() {
	return this->value->incrementReference();
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

//Override
std::string Entry::getClassName() {
	return "Entry";
}
