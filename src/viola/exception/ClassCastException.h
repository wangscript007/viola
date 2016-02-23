/*
 * ClassCastException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "RuntimeException.h"

class ClassCastException: public RuntimeException {
public:
	ClassCastException();
	~ClassCastException();

	virtual std::string getClassName();
};

