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
	fp = fopen(file->getAbsolutePath().c_str(), "r");
	if (fp == NULL) {
		throw FileNotFoundException("unexpected error. " + file->toString());
	}
}

FileReader::~FileReader() {

}

int FileReader::read() throw (IOException) {
	return fgetc(fp);
}

int FileReader::read(char cbuf[]) throw (IOException) {
	return 0;
}

int FileReader::read(char cbuf[], int offset, int length) throw (IOException) {
	return 0;
}

void FileReader::close() throw (IOException) {
	fclose(fp);
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
