/*
 * ExceptionTest.cpp
 *
 *  Created on: 2015/10/17
 *      Author: tsubaki
 */

#include "Exception.h"

int main() {

	try {
		throw new Exception("foobar");
	} catch (Exception* e) {
		printf("Exception: <%s>\n", e->toString().c_str());
		delete e;
	}

	return 0;
}
