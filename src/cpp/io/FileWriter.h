/*
 * FileWriter.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_IO_FILEWRITER_H_
#define CPP_IO_FILEWRITER_H_

#include "Object.h"
#include "File.h"

class FileWriter: public Object {
public:
	FileWriter(File* file);
	FileWriter(File* file, bool append);
	virtual ~FileWriter();

	void write(std::string line);
	void append(std::string line);
	void flush();

	void close();
};

#endif /* CPP_IO_FILEWRITER_H_ */
