/*
 * FileWriter.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPPDK_IO_FILEWRITER_H_
#define CPPDK_IO_FILEWRITER_H_

class FileWriter {
public:
	FileWriter(File* file);
	FileWriter(File* file, bool append);
	virtual ~FileWriter();

	void write(std::string line);
	void append(std::string line);
	void flush();

	void close();
};

#endif /* CPPDK_IO_FILEWRITER_H_ */
