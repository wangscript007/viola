/*
 * FileReader.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "FileReader.h"

FileReader::FileReader(
		std::shared_ptr<File> file)
				throw (std::shared_ptr<FileNotFoundException>) {
	// TODO Auto-generated constructor stub

}

FileReader::~FileReader() {
	// TODO Auto-generated destructor stub
}

void FileReader::flush() throw (std::shared_ptr<IOException>) {

}

void FileReader::close() throw (std::shared_ptr<IOException>) {

}

int FileReader::hashCode() {
	return 0;
}

bool FileReader::equals(Object* obj) {
	return true;
}

std::string FileReader::getClassName() {
	return "FileReader";
}

std::string FileReader::toString() {
	return "";
}
