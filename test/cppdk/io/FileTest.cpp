/*
 * FileTest.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "Strings.h"
#include "File.h"

int main() {
	Strings* str = new Strings();
	File* file = new File(str);

	delete file;
	delete str;

	return 0;
}

