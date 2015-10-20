/*
 * Throwable.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "Throwable.h"

Throwable::Throwable() {
	message = "";
	cause = NULL;
}

Throwable::Throwable(std::string message) {
	this->message = message;
	this->cause = NULL;
}
Throwable::Throwable(std::string message, Throwable* cause) {
	this->message = message;
	this->cause = cause;
}

Throwable::~Throwable() {
}

std::string Throwable::getMessage() {
	return message;
}

Throwable* Throwable::getCause() {
	return cause;
}

std::string Throwable::getClassName() {
	return "Throwable";
}

std::string Throwable::toString() {
	std::string str(getClassName());
	str.append("[");
	str.append("message: ");
	str.append(getMessage());
	str.append("]");
	return str;
}
