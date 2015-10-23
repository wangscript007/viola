/*
 * ArrayListTest.cpp
 *
 *  Created on: 2015/10/10
 *      Author: tsubaki
 */

#include "viola.h"

void dump(_ArrayList list) {
	printf("[dump]\n");
	printf("className: <%s>\n", list->getClassName().c_str());
	printf("size: <%d>\n", list->size());
	printf("hashCode: <%d>\n", list->hashCode());
	printf("toChar: <%s>\n", list->toChar());

	for (int i = 0; i < list->size(); i++) {
		printf("<%s>\n", list->get(i)->toChar());
	}

}

int hashCode() {
	int ret = 0;

	_ArrayList list = std::make_shared<ArrayList>();
	{
		_Integer arg1 = std::make_shared<Integer>(1234);
		_Integer arg2 = std::make_shared<Integer>(5678);
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

