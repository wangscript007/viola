/*
 * IOException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */


#pragma once
#include "Exception.h"

class IOException: public Exception {
public:
	IOException();
	IOException(std::string message);
	virtual ~IOException();

	virtual std::string getClassName();
};
