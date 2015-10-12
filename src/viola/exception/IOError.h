/*
 * IOError.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_IO_IOERROR_H_
#define VIOLA_IO_IOERROR_H_

#include "Error.h"

class IOError: public Error {
public:
	IOError();
	virtual ~IOError();
};

#endif /* VIOLA_IO_IOERROR_H_ */
