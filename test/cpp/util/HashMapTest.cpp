/*
 * HashMapTest.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "../../../src/cpp/util/HashMap.h"

#include "../../../src/cpp/lang/Integer.h"

int main() {
	Integer* arg1 = new Integer(1);
	Integer* arg2 = new Integer(2);

	HashMap* map = new HashMap();
	map->put(arg1, arg2);
	printf("size: <%d>\n", map->size());
	Integer* five = new Integer(5);
	Object* value = map->get(five);
	if (value == NULL) {
		printf("value is null.\n");
	}
	Object::tryDelete(2, five, value);

	Integer* one = new Integer(1);
	Object* value2 = map->get(one);
	printf("key: <%d>, value: <%d>\n", one->get(), ((Integer*) value2)->get());
	Object::tryDelete(2, one, value2);

	Object::tryDelete(map);
	return 0;
}
