/*
 * ExceptionTest.cpp
 *
 *  Created on: 2015/10/17
 *      Author: tsubaki
 */

#include "viola.h"

int main() {

	try {
		throw new Exception("foobar");
	} catch (Exception* e) {
		printf("Exception: <%s>\n", e->toChar());
		delete e;
	}

	return 0;
}
