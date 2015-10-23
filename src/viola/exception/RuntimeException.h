/*
 * RuntimeException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_RUNTIMEEXCEPTION_H_
#define VIOLA_LANG_RUNTIMEEXCEPTION_H_

#include "Exception.h"

class RuntimeException: public Exception {
public:
	RuntimeException();
	virtual ~RuntimeException();

	virtual std::string getClassName();
};

#endif /* VIOLA_LANG_RUNTIMEEXCEPTION_H_ */
