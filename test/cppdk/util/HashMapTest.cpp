/*
 * HashMapTest.cpp
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#include "HashMap.h"

int main() {
	HashMap<int, int>* map = new HashMap<int, int>();
	map->put(1, 2);
	printf("size: <%d>\n", map->size());

	delete map;
	return 0;
}
