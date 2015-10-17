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
	//printf("deleted: <%s>\n", internal.c_str());
}

void Strings::append(string str) {
	internal.append(str);
}

string Strings::replace(string str1, string str2) {
	std::string::size_type Pos(internal.find(str1));

	while (Pos != std::string::npos) {
		internal.replace(Pos, str1.length(), str2);
		Pos = internal.find(str1, Pos + str2.length());
	}

	return internal;
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
bool Strings::equals(Object* obj) {
	return this->equals((Strings*) obj);
}

//Override
string Strings::getClassName() {
	return "Strings";
}

//Override
std::string Strings::toString() {
	return internal;
}
