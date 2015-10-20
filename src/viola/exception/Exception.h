/*
 * Exception.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_EXCEPTION_H_
#define VIOLA_LANG_EXCEPTION_H_

#include "Throwable.h"

class Exception: public Throwable {
public:
	Exception();
	Exception(std::string message);
	Exception(std::string message, Throwable* cause);
	virtual ~Exception();

	virtual std::string getClassName();
};

#endif /* VIOLA_LANG_EXCEPTION_H_ */
