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

	printf("obj1.className: <%s>\n", arg1->getClassName().c_str());

	printf("obj1.hashCode: <%d>\n", arg1->hashCode());
	printf("obj2.hashCode: <%d>\n", arg2->hashCode());

	printf("obj1.equals(obj1): <%d>\n", arg1->equals(arg1.get()));
	printf("obj1.equals(obj2): <%d>\n", arg1->equals(arg2.get()));

	printf("obj1.toString(): <%s>\n", arg1->toString().c_str());

	ret = ret + Assert::assertEquals(arg1, arg1);
	ret = ret + !Assert::assertEquals(arg1, arg2);

	return ret;
}

