/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Entry.h"

Entry::Entry(object key, object value) {
	this->key = key;
	this->value = value;
	this->next = NULL;
}

Entry::~Entry() {
//	printf("deleted.\n");
}

object Entry::getKey() {
	return key;
}
object Entry::getValue() {
	return value;
}

void Entry::setValue(object value) {
	this->value = value;
}

Entry* Entry::getNext() {
	return next;
}

void Entry::setNext(Entry* next) {
	this->next = next;
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

bool Entry::equals(Object* obj) {
	if (obj == this) {
		return true;
	}

	Entry* entry = (Entry*) obj;
	if (this->key.get()->equals(entry->getKey().get())
			&& this->value.get()->equals(entry->getValue().get())) {
		return true;
	}
	return false;
}

//Override
string Entry::toString() {
	string str("Entry[");
	str.append(this->key->toString());
	str.append(": ");
	str.append(this->value->toString());
	str.append("]");
	return str;
}

//Override
string Entry::getClassName() {
	return "Entry";
}
