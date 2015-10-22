/*
 * HasHMapTest.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "viola.h"

void dump(_HashMap map) {
	printf("[dump] in. ---------\n");
	printf("className: <%s>\n", map->getClassName().c_str());
	printf("hashCode: <%d>\n", map->hashCode());
	printf("capacity: <%d>\n", map->getCapacity());
	printf("threshold: <%d>\n", map->getThreshold());
	printf("size: <%d>\n", map->size());
	printf("isEmpty: <%d>\n", map->isEmpty());
	printf("toString: <%s>\n", map->toString().c_str());
	printf("[dump] out. --------\n");
}

int containsKey() {
	printf("[containsKey]\n");
	int ret = 0;
	_HashMap map = std::make_shared<HashMap>(100);
	dump(map);

	_String key = std::make_shared<Strings>("foobar");
	_String value = std::make_shared<Strings>("hoge");

	object previous = map->put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}

	bool contains = map->containsKey(key);
	printf("key.hashCode: <%d>\n", key->hashCode());
	printf("containsKey: <%d>\n", contains);
	ret = ret + !contains;

	_String key2 = std::make_shared<Strings>("foobar");
	bool contains2 = map->containsKey(key2);
	printf("key2.hashCode: <%d>\n", key2->hashCode());
	printf("key2.containsKey: <%d>\n", contains2);
	ret = ret + !contains2;

	map->clear();
	return ret;
}

int put() {
	printf("[put]\n");
	int ret = 0;
	_HashMap map = std::make_shared<HashMap>(130);
	dump(map);

	_String key = std::make_shared<Strings>("foobar");
	_String value = std::make_shared<Strings>("hoge");

	_Object previous = map->put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}

	_Object got = map->get(key);
	printf("got.hashCode<%d>\n", got->hashCode());
	printf("got: <%s>\n", ((Strings*) got.get())->toString().c_str());
	if (!value->equals(got.get())) {
		ret = ret + 1;
	}

	map->clear();
	return ret;
}

int remove() {
	printf("[remove]\n");
	int ret = 0;
	_HashMap map = std::make_shared<HashMap>(300);
	dump(map);

	_String key = std::make_shared<Strings>("foobar");
	_String value = std::make_shared<Strings>("hoge");

	_Object previous = map->put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}
	_Object got = map->get(key);
	printf("got.hashCode<%d>\n", got->hashCode());
	printf("got: <%s>\n", ((Strings*) got.get())->toString().c_str());
	if (!value->equals(got.get())) {
		ret = ret + 1;
	}
	dump(map);

	_Object removed = map->remove(key);
	if (removed != NULL) {
		printf("removed.hashCode<%d>\n", removed->hashCode());
		printf("removed: <%s>\n",
				((Strings*) removed.get())->toString().c_str());
	} else {
		ret = ret + 1;
	}

	dump(map);

	map->clear();
	return ret;
}

int capacity() {
	printf("[capacity]\n");
	int ret = 0;
	_HashMap map = std::make_shared<HashMap>(2);

	_String key1 = std::make_shared<Strings>("foobar1");
	_String key2 = std::make_shared<Strings>("foobar2");
	_String key3 = std::make_shared<Strings>("foobar3");
	_String key4 = std::make_shared<Strings>("foobar4");
	_String value = std::make_shared<Strings>("hoge1");
	_String value2 = std::make_shared<Strings>("hoge2");

	_Object previous1 = map->put(key1, value);
	if (previous1 != NULL) {
		ret = ret + 1;
	}
	dump(map);

	_Object previous2 = map->put(key2, value);
	if (previous2 != NULL) {
		ret = ret + 1;
	}
	dump(map);

	_Object previous3 = map->put(key3, value);
	if (previous3 != NULL) {
		ret = ret + 1;
	}
	dump(map);

	_Object previous4 = map->put(key4, value);
	if (previous4 != NULL) {
		ret = ret + 1;
	}
	dump(map);

	_Object previous5 = map->put(key4, value2);
	if (previous5 == NULL) {
		ret = ret + 1;
	} else {
		if (!((Strings*) previous5.get())->equals("hoge1")) {
			ret = ret + 1;
		}
	}
	dump(map);

	map->remove(key1);
	map->remove(key2);
	map->remove(key3);
	map->remove(key4);
	dump(map);

	map->clear();
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + containsKey();
	ret = ret + put();
	ret = ret + remove();
	ret = ret + capacity();

	return ret;
}
