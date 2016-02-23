/*
 * Throwable.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Throwable: public Object {
protected:
	std::string message;
	Throwable* cause;
public:
	Throwable();
	Throwable(std::string message);
	Throwable(std::string message, Throwable* cause);
	virtual ~Throwable();

	std::string getMessage();
	Throwable* getCause();

	virtual std::string getClassName();
	virtual std::string toString();
};

