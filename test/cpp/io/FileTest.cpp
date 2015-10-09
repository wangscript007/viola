/*
 * FileTest.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "../../../src/cpp/io/File.h"

#include "../../../src/cpp/lang/Strings.h"

int main() {
	File* file = new File("./foobar.txt");

	delete file;
	return 0;
}

