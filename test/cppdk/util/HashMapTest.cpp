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

	HashMap<Integer*, Integer*>* map = new HashMap<Integer*, Integer*>();
	map->put(arg1, arg2);
	printf("size: <%d>\n", map->size());

	Integer* value = map->get(new Integer(5));
	if (value == NULL) {
		printf("value is null.\n");
	}

	Integer* value2 = map->get(arg1);
	printf("key: <%d>, value: <%d>\n", arg1->get(), value2->get());

	delete map;
	return 0;
}
