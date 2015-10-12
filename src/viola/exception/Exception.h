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
	~Exception();
};

#endif /* VIOLA_LANG_EXCEPTION_H_ */
