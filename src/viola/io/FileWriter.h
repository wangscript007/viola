/*
 * FileWriter.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#pragma once
#include "File.h"
#include "Object.h"
#include "Closeable.h"
#include "Flushable.h"
#include "Appendable.h"
#include "FileNotFoundException.h"
#include "IOException.h"

class FileWriter: public Object,
		public Closeable,
		public Flushable,
		public Appendable {
public:
	FileWriter(std::shared_ptr<File> file) throw (FileNotFoundException);
	FileWriter(std::shared_ptr<File> file, bool append)
			throw (FileNotFoundException);
	~FileWriter();

	//Override
	void append(std::string line) throw (IOException);
	void write(std::string line) throw (IOException);
	void flush() throw (IOException);
	void close() throw (IOException);
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};
