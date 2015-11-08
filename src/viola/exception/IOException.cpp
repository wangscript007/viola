/*
 * IOException.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "IOException.h"

IOException::IOException() {
	// TODO Auto-generated constructor stub

}

IOException::IOException(std::string message) {
	this->message = message;
}

IOException::~IOException() {
	// TODO Auto-generated destructor stub
}

std::string IOException::getClassName() {
	return "IOException";
}
