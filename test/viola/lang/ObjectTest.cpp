/*
 * ObjectTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Object.h"

typedef std::shared_ptr<Object> object;

int main() {
	int ret = 0;

	object arg1 = std::make_shared<Object>();
	object arg2 = std::make_shared<Object>();

	printf("obj1.className: <%s>\n", arg1.get()->getClassName().c_str());

	printf("obj1.hashCode: <%d>\n", arg1.get()->hashCode());
	printf("obj2.hashCode: <%d>\n", arg2.get()->hashCode());

	printf("obj1.equals(obj1): <%d>\n", arg1.get()->equals(arg1.get()));
	printf("obj1.equals(obj2): <%d>\n", arg1.get()->equals(arg2.get()));

	printf("obj1.toString(): <%s>\n", arg1.get()->toString().c_str());

	return ret;
}

