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

	Integer* value1 = (Integer*) list.get(0).get();
	Integer* value2 = (Integer*) list.get(1).get();
	printf("[0]: <%d>\n", value1->get());
	printf("[1]: <%d>\n", value2->get());

	list.clear();
	printf("size: <%d>\n", list.size());

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}

