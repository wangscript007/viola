/*
 * String.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "Strings.h"

Strings::Strings() {
	//noop;
}

Strings::Strings(string str) {
	internal = str;
}

Strings::~Strings() {
	//noop;
}

void Strings::append(string str) {
	internal.append(str);
}

bool Strings::equals(Object* obj) {
	return this->equals((Strings*) obj);
}

bool Strings::equals(Strings* str) {
	return this->equals(str->toString());
}

bool Strings::equals(object obj) {
	return this->equals((Strings*) obj.get());
}

bool Strings::equals(string str) {
	int size = str.size();
	int internalSize = internal.size();

	if (size != internalSize) {
		return false;
	}

	if (strncmp(internal.c_str(), str.c_str(), size) != 0) {
		return false;
	}

	return true;
}

bool Strings::isEmpty() {
	return internal.empty();
}

std::string Strings::toString() {
	return internal;
}

int Strings::length() {
	return internal.length();
}

//Override
int Strings::hashCode() {
	int hashCode = 0;
	if (this->isEmpty()) {
		return hashCode;
	}

	int n = this->length();
	for (int i = 0; i < n; i++) {
		int root = 31;
		for (int j = 0; j < (n - 1); j++) {
			root = root * root;
		}
		char c = internal.at(i);
		hashCode = hashCode + c * root;
	}

	return hashCode;
}

//Override
string Strings::getClassName() {
	return "Strings";
}
