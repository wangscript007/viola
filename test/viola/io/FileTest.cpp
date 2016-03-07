/*
 * FileTest.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	_File file = std::make_shared<File>("/tmp/viola.tmp");
	System::out::println(file);
	System::out::println(file->exists());
	return 0;
}

