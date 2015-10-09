/*
 * String.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "../../cpp/lang/Strings.h"

Strings::Strings() {
	//noop;
}

Strings::Strings(std::string str) {
	internal = str;
}

Strings::~Strings() {
	//noop;
}

void Strings::append(std::string str) {
	internal.append(str);
}
bool Strings::equals(std::string str) {
	int size = str.size();
	if (strncmp(internal.c_str(), str.c_str(), size) == 0) {
		return true;
	}

	return false;
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
