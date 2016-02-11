/*
 * SystemTest.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	System::out::println("foobar" + Long(1).toString());
	System::out::println("t: " + Strings::valueOf(System::currentTimemillis()));

	Object* obj = NULL;
	System::out::println(obj);
	delete obj;

	return 0;
}
