/*
 * IOError.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "Error.h"

class IOError: public Error {
public:
	IOError();
	~IOError();

	virtual std::string getClassName();
};

