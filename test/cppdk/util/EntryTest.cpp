/*
 * EntryTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include <string>
#include "Entry.h"

int assertEquals(int expected, int actual) {
	if (expected == actual) {
		return 0;
	}
	return 1;
}

int hashCodeTest() {
	int ret = 0;

	Entry<int, int>* entry = new Entry<int, int>(1, 2);
	printf("hashCode: <%d>\n", entry->hashCode());
	printf("key: <%d>\n", entry->getKey());
	printf("value: <%d>\n", entry->getValue());

	ret = ret + assertEquals(0, entry->hashCode());
	ret = ret + assertEquals(1, entry->getKey());
	ret = ret + assertEquals(2, entry->getValue());

	delete entry;
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}
