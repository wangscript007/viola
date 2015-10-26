/*
 * FileAppender.h
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LOG_FILEAPPENDER_H_
#define SRC_VIOLA_LOG_FILEAPPENDER_H_

#include "Appender.h"

class FileAppender: public Appender {
public:
	FileAppender();
	virtual ~FileAppender();

	//Override
	void append(std::string message);
	std::string getClassName();
};

#endif /* SRC_VIOLA_LOG_FILEAPPENDER_H_ */
