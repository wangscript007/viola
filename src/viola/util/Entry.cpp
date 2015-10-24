/*
 * Entry.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Entry.h"

Entry::Entry(Entry* e) {
	this->key = e->getKey();
	this->value = e->getValue();
	this->next = e->getNext();
}

Entry::Entry(std::shared_ptr<Object> key, std::shared_ptr<Object> value) {
	this->key = key;
	this->value = value;
	this->next = NULL;
}

Entry::~Entry() {
//	printf("deleted.\n");
}

std::shared_ptr<Object> Entry::getKey() {
	return key;
}

void Entry::setKey(std::shared_ptr<Object> key) {
	this->key = key;
}

std::shared_ptr<Object> Entry::getValue() {
	return value;
}

void Entry::setValue(std::shared_ptr<Object> value) {
	this->value = value;
}

std::shared_ptr<Object> Entry::getNext() {
	return next;
}

void Entry::setNext(std::shared_ptr<Object> next) {
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
std::string Entry::toString() {
	std::string str;
	str.append(this->key->toString());
	str.append(": ");
	str.append(this->value->toString());
	return str;
}

//Override
std::string Entry::getClassName() {
	return "Entry";
}
