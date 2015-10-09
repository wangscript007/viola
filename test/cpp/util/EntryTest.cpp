/*
 * EntryTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include <string>
#include "Integer.h"
#include "Entry.h"

int assertEquals(int expected, int actual) {
	if (expected == actual) {
		return 0;
	}
	return 1;
}

int hashCodeTest() {
	int ret = 0;

	Integer* arg1 = new Integer(1);
	Integer* arg2 = new Integer(2);

	Entry* entry = new Entry(arg1, arg2);
	printf("hashCode: <%d>\n", entry->hashCode());

	Integer* key = (Integer*) entry->getKey();
	Integer* value = (Integer*) entry->getValue();
	printf("key: <%d>\n", key->get());
	printf("value: <%d>\n", value->get());

	ret = ret + assertEquals(0, entry->hashCode());
	ret = ret + assertEquals(1, key->get());
	ret = ret + assertEquals(2, value->get());

	Object::tryDelete(4, arg1, arg2, key, value);
	Object::tryDelete(entry);
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}
