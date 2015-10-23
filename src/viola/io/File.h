/*
 * File.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef VIOLA_FILE_H_
#define VIOLA_FILE_H_

#include <stdio.h>
#include "Object.h"
#include "Strings.h"
#include "IOException.h"

class File: public Object {
private:
	std::string path;
public:
	File(std::string path);
	~File();

	bool createNewFile() throw (std::shared_ptr<IOException>);
	bool deleteFile();
	bool exists();
	std::string getAbsolutePath();
	std::string getName();
	bool isFile();
	bool isDirectory();
	bool mkdir();
	bool mkdirs();

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};

#endif /* VIOLA_FILE_H_ */
