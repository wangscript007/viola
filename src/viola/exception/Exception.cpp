/*
 * Exception.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "Exception.h"

Exception::Exception() {

}

Exception::Exception(string message) {
	this->message = message;
}

Exception::Exception(string message, Throwable* cause) {
	this->message = message;
	this->cause = cause;
}
Exception::~Exception() {
}

string Exception::getClassName() {
	return "Exception";
}

