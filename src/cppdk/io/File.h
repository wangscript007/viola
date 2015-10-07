/*
 * File.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef CPPDK_FILE_H_
#define CPPDK_FILE_H_

#include <stdio.h>
#include <Strings.h>

class File {
public:
	File(Strings* path);
	virtual ~File();
};

#endif /* CPPDK_FILE_H_ */
