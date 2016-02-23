/*
 * SocketException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "IOException.h"

class SocketException: public IOException {
public:
	SocketException();
	virtual ~SocketException();

	virtual std::string getClassName();
};
