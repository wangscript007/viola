/*
 * File.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef CPPDK_FILE_H_
#define CPPDK_FILE_H_

#include <stdio.h>
#include <string>

class File {
public:
	File(std::string path);
	virtual ~File();
};

#endif /* CPPDK_FILE_H_ */
