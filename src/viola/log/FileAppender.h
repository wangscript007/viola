/*
 * FileAppender.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#pragma once
#include "Appender.h"

class FileAppender: public Appender {
public:
	FileAppender();
	virtual ~FileAppender();

	//Override
	void append(std::string message);
	std::string getClassName();
};

