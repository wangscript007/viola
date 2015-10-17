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
	Exception(string message);
	Exception(string message, Throwable* cause);
	virtual ~Exception();

	virtual string getClassName();
};

#endif /* VIOLA_LANG_EXCEPTION_H_ */
