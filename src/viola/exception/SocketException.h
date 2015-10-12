/*
 * SocketException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_EXCEPTION_SOCKETEXCEPTION_H_
#define VIOLA_EXCEPTION_SOCKETEXCEPTION_H_

#include "IOException.h"

class SocketException: public IOException {
public:
	SocketException();
	~SocketException();
};

#endif /* VIOLA_EXCEPTION_SOCKETEXCEPTION_H_ */
