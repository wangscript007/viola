/*
 * String.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include <Strings.h>

Strings::Strings() {
}

Strings::Strings(std::string str) {
	internal = str;
}

Strings::~Strings() {
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
