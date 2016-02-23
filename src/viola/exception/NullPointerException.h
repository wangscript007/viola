/*
 * NullPointerException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "RuntimeException.h"

class NullPointerException: public RuntimeException {
public:
	NullPointerException();
	~NullPointerException();

	virtual std::string getClassName();
};

