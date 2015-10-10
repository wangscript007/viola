/*
 * HashMapTest.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "HashMap.h"
#include "Integer.h"
#include "Assert.h"

int main() {
	int ret = 0;

	Integer arg1(1);
	Integer arg2(2);

	HashMap map;
	printf("className: <%s>\n", map.getClassName().c_str());

	map.put(arg1, arg2);
	int size = map.size();
	printf("size: <%d>\n", size);
	ret = ret + Assert::assertEquals(1, size);

	Integer five(5);
	Object* value = map.get(five);
	if (value == NULL) {
		printf("value is null.\n");
	} else {
		ret = ret + 1;
		printf("value is <%d>\n", ((Integer*) value)->get());
	}

	Integer one(1);
	Object* value2 = map.get(one);
	printf("key: <%d>, value: <%d>\n", one.get(), ((Integer*) value2)->get());

	return ret;
}
