/*
 * EntryTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include <string>
#include "Entry.h"
#include "Integer.h"

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
	printf("key: <%d>\n", ((Integer*) entry->getKey())->get());
	printf("value: <%d>\n", ((Integer*) entry->getValue())->get());

	ret = ret + assertEquals(0, entry->hashCode());
	ret = ret + assertEquals(1, ((Integer*) entry->getKey())->get());
	ret = ret + assertEquals(2, ((Integer*) entry->getValue())->get());

	delete entry;
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}
