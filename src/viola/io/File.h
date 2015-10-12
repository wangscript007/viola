/*
 * File.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef CPPDK_FILE_H_
#define CPPDK_FILE_H_

#include <stdio.h>

#include "Object.h"
#include "Strings.h"

using namespace std;

class File: public Object {
public:
	File(string path);
	~File();

	bool createNewFile();
	bool deleteFile();
	bool exists();
	string getAbsolutePath();
	string getName();
	bool isFile();
	bool isDirectory();
	bool mkdir();
	bool mkdirs();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);

	//Override
	string getClassName();

};

#endif /* CPPDK_FILE_H_ */
