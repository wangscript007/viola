/*
 * FileNotFoundException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */


#pragma once
#include "IOException.h"

class FileNotFoundException: public IOException {
public:
	FileNotFoundException();
	FileNotFoundException(std::string message);
	~FileNotFoundException();

	virtual std::string getClassName();
};
