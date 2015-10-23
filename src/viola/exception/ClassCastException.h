/*
 * ClassCastException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_CLASSCASTEXCEPTION_H_
#define VIOLA_LANG_CLASSCASTEXCEPTION_H_

#include "RuntimeException.h"

class ClassCastException: public RuntimeException {
public:
	ClassCastException();
	~ClassCastException();

	virtual std::string getClassName();
};

#endif /* VIOLA_LANG_CLASSCASTEXCEPTION_H_ */
