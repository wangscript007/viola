/*
 * FileTest.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	_File file = std::make_shared<File>("./foobar.txt");
	System::out::println(file);
	return 0;
}

