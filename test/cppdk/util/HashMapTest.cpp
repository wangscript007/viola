/*
 * HashMapTest.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "HashMap.h"
#include "Integer.h"

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
	delete five;

	Integer* one = new Integer(1);
	Object* value2 = map->get(one);
	printf("key: <%d>, value: <%d>\n", one->get(), ((Integer*) value2)->get());
	delete one;

	delete map;
	return 0;
}
