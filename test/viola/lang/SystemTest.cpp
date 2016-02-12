/*
 * SystemTest.cpp
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	System::out::println("foobar" + Long(1).toString());
	System::out::println(
			"timestamp(millis): "
					+ Strings::valueOf(System::currentTimemillis()));
	System::out::println(
			"timestamp(seconds): "
					+ Strings::valueOf(System::currentTimeseconds()));

	Object* obj = NULL;
	System::out::println(obj);
	delete obj;

	return 0;
}
