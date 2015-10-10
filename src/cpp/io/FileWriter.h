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
using namespace std;

typedef std::shared_ptr<File> file;

class FileWriter: public Object {
public:
	FileWriter(file file);
	FileWriter(file file, bool append);
	~FileWriter();

	void close();
	void append(string line);
	void flush();
	void write(string line);

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* CPP_IO_FILEWRITER_H_ */
