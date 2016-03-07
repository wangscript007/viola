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

std::string File::getAbsolutePath() {
	return path;
}

bool File::exists() {
	if (access(path.c_str(), F_OK) != -1) {
		return true;
	}

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
