/*
 * FileNotFoundException.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_IO_FILENOTFOUNDEXCEPTION_H_
#define VIOLA_IO_FILENOTFOUNDEXCEPTION_H_

#include "IOException.h"

class FileNotFoundException: public IOException {
public:
	FileNotFoundException();
	~FileNotFoundException();
};

#endif /* VIOLA_IO_FILENOTFOUNDEXCEPTION_H_ */
