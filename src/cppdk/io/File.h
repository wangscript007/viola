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
	File(std::string path);
	virtual ~File();

	bool createNewFile();
	bool deleteFile();
	bool exists();
	std::string getAbsolutePath();
	std::string getName();
	bool isFile();
	bool isDirectory();
	bool mkdir();
	bool mkdirs();

};

#endif /* CPPDK_FILE_H_ */
