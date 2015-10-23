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
	~IOError();

	virtual std::string getClassName();
};

#endif /* VIOLA_IO_IOERROR_H_ */
