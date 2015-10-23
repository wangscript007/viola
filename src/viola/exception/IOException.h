/*
 * IOException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_IO_IOEXCEPTION_H_
#define VIOLA_IO_IOEXCEPTION_H_

#include "Exception.h"

class IOException: public Exception {
public:
	IOException();
	virtual ~IOException();

	virtual std::string getClassName();
};

#endif /* VIOLA_IO_IOEXCEPTION_H_ */
