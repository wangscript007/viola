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
	bool equals(Object* obj);

	//Override
	string getClassName();

};

#endif /* VIOLA_IO_FILEREADER_H_ */
