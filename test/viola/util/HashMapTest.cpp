/*
 * HasHMapTest.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "HashMap.h"
#include "Strings.h"

typedef std::shared_ptr<Strings> strings;

void dump(HashMap* map) {
	printf("[dump]\n");
	printf("className: <%s>\n", map->getClassName().c_str());
	printf("hashCode: <%d>\n", map->hashCode());
	printf("size: <%d>\n", map->size());
	printf("isEmpty: <%d>\n", map->isEmpty());
}

int containsKeyTest() {
	printf("[containsKeyTest]\n");
	int ret = 0;
	HashMap map;
	dump(&map);

	strings key = std::make_shared<Strings>("foobar");
	strings value = std::make_shared<Strings>("hoge");

	object previous = map.put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}
	dump(&map);

	bool contains = map.containsKey(key);
	dump(&map);
	printf("key.hashCode: <%d>\n", key.get()->hashCode());
	printf("containsKey: <%d>\n", contains);
	ret = ret + !contains;

	strings key2 = std::make_shared<Strings>("foobar");
	bool contains2 = map.containsKey(key2);
	dump(&map);
	printf("key2.hashCode: <%d>\n", key2.get()->hashCode());
	printf("key2.containsKey: <%d>\n", contains2);
	ret = ret + !contains2;

	map.clear();
	dump(&map);

	return ret;
}

int putTest() {
	printf("[putTest]\n");
	int ret = 0;
	HashMap map;
	dump(&map);

	strings key = std::make_shared<Strings>("foobar");
	strings value = std::make_shared<Strings>("hoge");

	object previous = map.put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}
	dump(&map);

	object got = map.get(key);
	dump(&map);
	printf("got: <%s>\n", ((Strings*) got.get())->toString().c_str());
	if (!value.get()->equals(((Strings*) got.get())->toString())) {
		ret = ret + 1;
	}

	map.clear();
	dump(&map);

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + containsKeyTest();
//	ret = ret + putTest();

	return ret;
}
