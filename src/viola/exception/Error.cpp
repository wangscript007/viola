/*
 * Error.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "Error.h"

Error::Error() {

}

Error::Error(string message) {
	this->message = message;
}

Error::Error(string message, Throwable* cause) {
	this->message = message;
	this->cause = cause;
}

Error::~Error() {
}

string Error::getClassName() {
	return "Error";
}
