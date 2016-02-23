/*
 * Exception.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "Throwable.h"

class Exception: public Throwable {
public:
	Exception();
	Exception(std::string message);
	Exception(std::string message, Throwable* cause);
	virtual ~Exception();

	virtual std::string getClassName();
};
