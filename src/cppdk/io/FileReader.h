/*
 * FileReader.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPPDK_IO_FILEREADER_H_
#define CPPDK_IO_FILEREADER_H_

#include "File.h"

class FileReader {
public:
	FileReader(File* file);
	virtual ~FileReader();

	std::string read();

	bool close();
};

#endif /* CPPDK_IO_FILEREADER_H_ */
