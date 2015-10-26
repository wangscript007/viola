/*
 * StandartOutAppender.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_STANDARDOUTAPPENDER_H_
#define SRC_VIOLA_LOG_STANDARDOUTAPPENDER_H_

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

#endif /* SRC_VIOLA_LOG_STANDARDOUTAPPENDER_H_ */
