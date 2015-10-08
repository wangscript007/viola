/*
 * Integer.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include <Integer.h>

Integer::Integer() {
	this->i = 0;
}

Integer::Integer(int i) {
	this->i = i;
}

Integer::~Integer() {
	// TODO Auto-generated destructor stub
}

int Integer::get() {
	return this->i;
}
