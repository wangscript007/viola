/*
 * StandartOutAppender.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#pragma once
#include "Appender.h"
#include "System.h"

class StandardOutAppender: public Appender {
public:
	StandardOutAppender();
	virtual ~StandardOutAppender();

	//Override
	void append(std::string message);
	std::string getClassName();
};
