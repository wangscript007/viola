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

	Integer* arg1 = new Integer(1);
	Integer* arg2 = new Integer(2);

	HashMap* map = new HashMap();
	printf("className: <%s>\n", map->getClassName().c_str());

	map->put(arg1, arg2);
	printf("size: <%d>\n", map->size());
	ret = ret + Assert::assertEquals(1, map->size());
	Object::tryDelete(2, arg1, arg2);

	Integer* five = new Integer(5);
	Object* value = map->get(five);
	if (value == NULL) {
		printf("value is null.\n");
	} else {
		ret = ret + 1;
		printf("value is <%d>\n", ((Integer*) value)->get());
	}
	Object::tryDelete(five);
	Object::tryDelete(value); //NULL

	Integer* one = new Integer(1);
	Object* value2 = map->get(one);
	printf("key: <%d>, value: <%d>\n", one->get(), ((Integer*) value2)->get());
	Object::tryDelete(2, one, value2);

	Object::tryDelete(map);
	return ret;
}
