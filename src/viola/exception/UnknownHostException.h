/*
 * UnknownHostException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_EXCEPTION_UNKNOWNHOSTEXCEPTION_H_
#define VIOLA_EXCEPTION_UNKNOWNHOSTEXCEPTION_H_

#include "IOException.h"

class UnknownHostException: public IOException {
public:
	UnknownHostException();
	~UnknownHostException();
};

#endif /* VIOLA_EXCEPTION_UNKNOWNHOSTEXCEPTION_H_ */
