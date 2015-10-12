/*
 * ArrayListTest.cpp
 *
 *  Created on: 2015/10/10
 *      Author: tsubaki
 */

#include "Integer.h"
#include "ArrayList.h"
#include "Assert.h"

typedef std::shared_ptr<Integer> integer;

int hashCodeTest() {
	int ret = 0;

	ArrayList list;
	printf("className: <%s>\n", list.getClassName().c_str());

	integer arg1 = std::make_shared<Integer>(1234);
	integer arg2 = std::make_shared<Integer>(5678);
	list.add(arg1);
	list.add(arg2);
	printf("size: <%d>\n", list.size());
	printf("hashCode: <%d>\n", list.hashCode());

	object obj1 = list.get(0);
	object obj2 = list.get(1);
	printf("obj1: <%d>\n", ((Integer*) obj1.get())->get());
	printf("obj2: <%d>\n", ((Integer*) obj2.get())->get());

	list.clear();
	printf("size: <%d>\n", list.size());
	printf("hashCode: <%d>\n", list.hashCode());

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}

