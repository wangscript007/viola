/*
 * ExceptionTest.cpp
 *
 *  Created on: 2015/10/17
 *      Author: tsubaki
 */

#include "viola.h"

int main() {

	try {
		throw Exception("foobar");
	} catch (Exception& e) {
		System::out::println(e);
	}

	return 0;
}
