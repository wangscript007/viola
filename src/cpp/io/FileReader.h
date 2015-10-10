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

using namespace std;

typedef std::shared_ptr<File> file;

class FileReader: public Object {
public:
	FileReader(file file);
	~FileReader();

	string read();
	bool close();

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* CPP_IO_FILEREADER_H_ */
