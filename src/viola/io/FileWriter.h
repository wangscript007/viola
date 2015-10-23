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
	FileWriter(
			std::shared_ptr<File> file) throw (std::shared_ptr<
					FileNotFoundException>);
	FileWriter(std::shared_ptr<File> file,
			bool append) throw (std::shared_ptr<FileNotFoundException>);
	~FileWriter();

	//Override
	void append(std::string line) throw (std::shared_ptr<IOException>);
	void write(std::string line) throw (std::shared_ptr<IOException>);
	void flush() throw (std::shared_ptr<IOException>);
	void close() throw (std::shared_ptr<IOException>);
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};

#endif /* VIOLA_IO_FILEWRITER_H_ */
