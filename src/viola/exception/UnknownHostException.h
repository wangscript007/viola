/*
 * UnknownHostException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "IOException.h"

class UnknownHostException: public IOException {
public:
	UnknownHostException();
	~UnknownHostException();

	virtual std::string getClassName();
};

