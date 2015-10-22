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

class FileReader: public Object {
public:
	FileReader(std::shared_ptr<File> file);
	~FileReader();

	std::string read();
	bool close();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);

	//Override
	std::string getClassName();

};

#endif /* VIOLA_IO_FILEREADER_H_ */
