/*
 * FileReader.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_IO_FILEREADER_H_
#define CPP_IO_FILEREADER_H_

#include "Object.h"
#include "File.h"

class FileReader: public Object {
public:
	FileReader(File* file);
	virtual ~FileReader();

	std::string read();
	bool close();

	//Override
	int hashCode();

	//Override
	std::string getClassName();

};

#endif /* CPP_IO_FILEREADER_H_ */
