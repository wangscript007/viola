/*
 * Integer.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "Integer.h"

Integer::Integer(int value) {
	this->i = value;
}

Integer::~Integer() {
	//noop
}

int Integer::get() {
	return this->i;
}

//Override
int Integer::hashCode() {
	return this->i;
}
