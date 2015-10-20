/*
 * FileWriter.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef VIOLA_IO_FILEWRITER_H_
#define VIOLA_IO_FILEWRITER_H_

#include "File.h"
#include "Object.h"

typedef std::shared_ptr<File> file;

class FileWriter: public Object {
public:
	FileWriter(file file);
	FileWriter(file file, bool append);
	~FileWriter();

	void close();
	void append(std::string line);
	void flush();
	void write(std::string line);

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);

	//Override
	std::string getClassName();

};

#endif /* VIOLA_IO_FILEWRITER_H_ */
