/*
 * FileReaderTest.cpp
 *
 *  Created on: 2015/11/08
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	_File f = std::make_shared<File>("/tmp/viola.tmp");

	FileReader* reader;
	try {
		reader = new FileReader(f);
		int read = reader->read();
		System::out::println(read);

		char buf[1];
		sprintf(buf, "%d", read);
		printf("%s\n", buf);

		reader->close();
		delete reader;
	} catch (Exception& e) {
		System::out::println(e);
	}

	return 0;
}
