/*
 * FileAppender.cpp
 *
 *  Created on: 2015/10/26
 *      Author: tsubaki
 */

#include "FileAppender.h"

FileAppender::FileAppender() {
	// TODO Auto-generated constructor stub

}

FileAppender::~FileAppender() {
	// TODO Auto-generated destructor stub
}

void FileAppender::append(std::string message) {

}

//Override
std::string FileAppender::getClassName() {
	return "FileAppender";
}
