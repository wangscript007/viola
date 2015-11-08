/*
 * FileReader.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef VIOLA_IO_FILEREADER_H_
#define VIOLA_IO_FILEREADER_H_

#include "File.h"
#include "Object.h"
#include "Closeable.h"
#include "Flushable.h"
#include "FileNotFoundException.h"

class FileReader: public Object, public Closeable, public Flushable {
public:
	FileReader(std::shared_ptr<File> file) throw (FileNotFoundException);
	~FileReader();

	std::string read();

	//Override
	void flush() throw (IOException);
	void close() throw (IOException);
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();
};

#endif /* VIOLA_IO_FILEREADER_H_ */
