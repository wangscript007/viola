/*
 * File.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "File.h"

File::File(std::string path) {
	this->path = path;
}

File::~File() {

}

bool File::exists() {
	return false;
}

uint32_t File::hashCode() {
	return 0;
}

bool File::equals(Object* obj) {
	return true;
}

std::string File::getClassName() {
	return "File";
}
std::string File::toString() {
	std::string str(getClassName());
	str.append("[");
	str.append(path);
	str.append("]");
	return str;
}
