/*
 * FileWriter.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "FileWriter.h"

FileWriter::FileWriter(std::shared_ptr<File> file) throw (FileNotFoundException) {
	// TODO Auto-generated constructor stub

}

FileWriter::FileWriter(std::shared_ptr<File> file, bool append)
		throw (FileNotFoundException) {
	// TODO Auto-generated constructor stub

}

FileWriter::~FileWriter() {
	// TODO Auto-generated destructor stub
}

void FileWriter::append(std::string line) throw (IOException) {

}

void FileWriter::write(std::string line) throw (IOException) {

}

void FileWriter::flush() throw (IOException) {

}

void FileWriter::close() throw (IOException) {

}

int FileWriter::hashCode() {
	return 0;
}

bool FileWriter::equals(Object* obj) {
	return true;
}

std::string FileWriter::getClassName() {
	return "FileWriter";
}

std::string FileWriter::toString() {
	return "";
}
