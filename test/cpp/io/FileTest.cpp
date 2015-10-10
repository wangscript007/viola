/*
 * FileTest.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "File.h"
#include "Strings.h"

int main() {
	File* file = new File("./foobar.txt");
	printf("className: <%s>\n", file->getClassName().c_str());

	delete file;
	return 0;
}

