/*
 * ArrayListTest.cpp
 *
 *  Created on: 2015/10/10
 *      Author: tsubaki
 */

#include "Integer.h"
#include "ArrayList.h"
#include "Assert.h"

using namespace std;
typedef std::shared_ptr<Integer> integer;
typedef std::shared_ptr<ArrayList> arrayList;

void dump(arrayList list) {
	printf("[dump]\n");
	printf("className: <%s>\n", list->getClassName().c_str());
	printf("size: <%d>\n", list->size());
	printf("hashCode: <%d>\n", list->hashCode());
	printf("toString: <%s>\n", list->toString().c_str());

	for (int i = 0; i < list->size(); i++) {
		object obj = list->get(i);
		printf("obj<%d>: <%d>\n", i, ((Integer*) obj.get())->get());
	}

}

int hashCode() {
	int ret = 0;

	arrayList list = make_shared<ArrayList>();
	{
		integer arg1 = make_shared<Integer>(1234);
		integer arg2 = make_shared<Integer>(5678);
		list->add(arg1);
		list->add(arg2);

		dump(list);

	}

	list->clear();

	dump(list);
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCode();

	return ret;
}

