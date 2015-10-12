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

int dump(ArrayList* list) {
	printf("className: <%s>\n", list->getClassName().c_str());
	printf("size: <%d>\n", list->size());
	printf("hashCode: <%d>\n", list->hashCode());

	for (int i = 0; i < list->size(); i++) {
		object obj = list->get(i);
		printf("obj<%d>: <%d>\n", i, ((Integer*) obj.get())->get());
	}

	return 0;
}

int hashCodeTest() {
	int ret = 0;

	ArrayList list;
	{
		integer arg1 = std::make_shared<Integer>(1234);
		integer arg2 = std::make_shared<Integer>(5678);
		list.add(arg1);
		list.add(arg2);

		dump(&list);

	}

	list.clear();
	printf("before cleared.\n");

	dump(&list);

//	delete list;
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}

