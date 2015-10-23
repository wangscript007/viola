/*
 * NullPointerException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_NULLPOINTEREXCEPTION_H_
#define VIOLA_LANG_NULLPOINTEREXCEPTION_H_

#include "RuntimeException.h"

class NullPointerException: public RuntimeException {
public:
	NullPointerException();
	~NullPointerException();

	virtual std::string getClassName();
};

#endif /* VIOLA_LANG_NULLPOINTEREXCEPTION_H_ */
