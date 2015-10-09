/*
 * Integer.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "../../cpp/lang/Integer.h"

Integer::Integer() {
	this->i = 0;
}

Integer::Integer(int i) {
	this->i = i;
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
