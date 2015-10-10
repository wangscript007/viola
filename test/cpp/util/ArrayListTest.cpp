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

	ArrayList<integer> list;
	printf("className: <%s>\n", list.getClassName().c_str());

	integer arg1 = std::make_shared<Integer>(1234);
	integer arg2 = std::make_shared<Integer>(5678);
	list.add(arg1);
	list.add(arg2);
	printf("size: <%d>\n", list.size());

	integer obj1 = list.get(0);
	integer obj2 = list.get(1);
	printf("[0]: <%d>\n", obj1->get());
	printf("[1]: <%d>\n", obj2->get());

	list.clear();
	printf("size: <%d>\n", list.size());

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}

