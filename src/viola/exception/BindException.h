/*
 * BindException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "SocketException.h"

class BindException: public SocketException {
public:
	BindException();
	~BindException();

	virtual std::string getClassName();
};
