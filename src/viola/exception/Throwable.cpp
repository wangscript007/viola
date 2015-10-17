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

Throwable::Throwable(string message) {
	this->message = message;
	this->cause = NULL;
}
Throwable::Throwable(string message, Throwable* cause) {
	this->message = message;
	this->cause = cause;
}

Throwable::~Throwable() {
}

string Throwable::getMessage() {
	return message;
}

Throwable* Throwable::getCause() {
	return cause;
}

string Throwable::getClassName() {
	return "Throwable";
}

string Throwable::toString() {
	string str(getClassName());
	str.append("[");
	str.append("message: ");
	str.append(getMessage());
	str.append("]");
	return str;
}
