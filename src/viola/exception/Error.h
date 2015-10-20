/*
 * Error.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_ERROR_H_
#define VIOLA_LANG_ERROR_H_

#include "Throwable.h"

class Error: public Throwable {
public:
	Error();
	Error(std::string message);
	Error(std::string message, Throwable* cause);
	virtual ~Error();

	virtual std::string getClassName();
};

#endif /* VIOLA_LANG_ERROR_H_ */
