/*
 * Appendable.h
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#pragma once
#include "IOException.h"

class Appendable: public Object {
public:
	Appendable();
	virtual ~Appendable();

	virtual void append(std::string line) throw (IOException);
};
