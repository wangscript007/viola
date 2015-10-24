/*
 * ObjectTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	int ret = 0;

	_Object arg1 = std::make_shared<Object>();
	_Object arg2 = std::make_shared<Object>();

	System::out::println("o1.class: " + arg1->getClassName());
	System::out::println("o1.hash: " + Integer(arg1->hashCode()).toString());
	System::out::println("o2.hash: " + Integer(arg2->hashCode()).toString());
	System::out::println(
			"o1.eq(o1): " + Boolean(arg1->equals(arg1.get())).toString());
	System::out::println(
			"o1.eq(o2): " + Boolean(arg1->equals(arg2.get())).toString());

	ret = ret + Assert::assertEquals(arg1, arg1);
	ret = ret + !Assert::assertEquals(arg1, arg2);

	return ret;
}

