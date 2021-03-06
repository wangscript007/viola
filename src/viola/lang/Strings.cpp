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

Strings::Strings(std::string str) {
	internal = str;
}

Strings::~Strings() {
	//noop;
	//printf("deleted: <%s>\n", internal.c_str());
}

void Strings::append(std::string str) {
	internal.append(str);
}

std::string Strings::replace(std::string str1, std::string str2) {
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

bool Strings::equals(std::shared_ptr<Object> obj) {
	return this->equals((Strings*) obj.get());
}

bool Strings::equals(std::string str) {
	uint32_t size = str.size();
	uint32_t internalSize = internal.size();

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

std::string Strings::valueOf(long value) {
	return std::to_string(value);
}

//Override
uint32_t Strings::hashCode() {
	uint32_t hashCode = 0;
	if (this->isEmpty()) {
		return hashCode;
	}

	uint32_t n = this->length();
	for (uint32_t i = 0; i < n; i++) {
		uint32_t root = 31;
		for (uint32_t j = 0; j < (n - 1); j++) {
			root = root * root;
		}
		int32_t c = internal.at(i);
		hashCode = hashCode + c * root;
	}

	return hashCode;
}

//Override
bool Strings::equals(Object* obj) {
	return this->equals((Strings*) obj);
}

//Override
std::string Strings::getClassName() {
	return "Strings";
}

//Override
std::string Strings::toString() {
	return internal;
}
