/*
 * BindException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_EXCEPTION_BINDEXCEPTION_H_
#define VIOLA_EXCEPTION_BINDEXCEPTION_H_

#include "SocketException.h"

class BindException: public SocketException {
public:
	BindException();
	~BindException();
};

#endif /* VIOLA_EXCEPTION_BINDEXCEPTION_H_ */
