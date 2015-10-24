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

	_Strings key = std::make_shared<Strings>("foobar");
	_Strings value = std::make_shared<Strings>("hoge");

	_Object previous = map->put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}

	bool contains = map->containsKey(key);
	System::out::println("key1.hash: " + Integer(key->hashCode()).toString());
	System::out::println("contains: " + Boolean(contains).toString());
	ret = ret + !contains;

	_Strings key2 = std::make_shared<Strings>("foobar");
	bool contains2 = map->containsKey(key2);
	System::out::println("key2.hash: " + Integer(key2->hashCode()).toString());
	System::out::println("contains: " + Boolean(contains2).toString());
	ret = ret + !contains2;

	map->clear();
	return ret;
}

int put() {
	printf("[put]\n");
	int ret = 0;
	_HashMap map = std::make_shared<HashMap>(130);
	dump(map);

	_Strings key = std::make_shared<Strings>("foobar");
	_Strings value = std::make_shared<Strings>("hoge");

	_Object previous = map->put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}

	_Object got = map->get(key);
	System::out::println("got: " + got->toString());
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

	_Strings key = std::make_shared<Strings>("foobar");
	_Strings value = std::make_shared<Strings>("hoge");

	_Object previous = map->put(key, value);
	if (previous != NULL) {
		ret = ret + 1;
	}
	_Object got = map->get(key);
	System::out::println("got: " + got->toString());
	if (!value->equals(got.get())) {
		ret = ret + 1;
	}
	dump(map);

	_Object removed = map->remove(key);
	if (removed != NULL) {
		System::out::println("removed: " + removed->toString());
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

	_Strings key1 = std::make_shared<Strings>("foobar1");
	_Strings key2 = std::make_shared<Strings>("foobar2");
	_Strings key3 = std::make_shared<Strings>("foobar3");
	_Strings key4 = std::make_shared<Strings>("foobar4");
	_Strings value = std::make_shared<Strings>("hoge1");
	_Strings value2 = std::make_shared<Strings>("hoge2");

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
