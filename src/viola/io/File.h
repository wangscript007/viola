/*
 * File.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#pragma once
#include <stdio.h>
#include <unistd.h>
#include "Object.h"
#include "Strings.h"
#include "IOException.h"

class File: public Object {
private:
	std::string path;
public:
	File(std::string path);
	~File();

	bool createNewFile() throw (IOException);
	bool deleteFile();
	bool exists();
	std::string getAbsolutePath();
	std::string getName();
	bool isFile();
	bool isDirectory();
	bool mkdir();
	bool mkdirs();

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};
