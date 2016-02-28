/*
 * FileReader.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "FileReader.h"

FileReader::FileReader(std::shared_ptr<File> file) throw (FileNotFoundException) {

	if (!file->exists()) {
		throw FileNotFoundException("file not found. " + file->toString());
	}

}

FileReader::~FileReader() {
	// TODO Auto-generated destructor stub
}

void FileReader::flush() throw (IOException) {

}

void FileReader::close() throw (IOException) {

}

uint32_t FileReader::hashCode() {
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
