/*
 * FileTest.cpp
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#include "File.h"

int main(){
	File* file = new File("foobar");

	delete file;

	return 0;
}

