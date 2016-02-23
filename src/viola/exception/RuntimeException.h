/*
 * RuntimeException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "Exception.h"

class RuntimeException: public Exception {
public:
	RuntimeException();
	virtual ~RuntimeException();

	virtual std::string getClassName();
};
