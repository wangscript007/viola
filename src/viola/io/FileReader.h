/*
 * FileReader.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#pragma once
#include <stdio.h>
#include "File.h"
#include "Object.h"
#include "Closeable.h"
#include "Reader.h"
#include "FileNotFoundException.h"

class FileReader: public Object, public Closeable, public Reader {
private:
	FILE* fp;
public:
	FileReader(std::shared_ptr<File> file) throw (FileNotFoundException);
	~FileReader();

	//Override
	int read() throw (IOException);
	int read(char cbuf[]) throw (IOException);
	int read(char cbuf[], int offset, int length) throw (IOException);
	void close() throw (IOException);
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();
};
