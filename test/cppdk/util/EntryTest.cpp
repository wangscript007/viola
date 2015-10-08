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

	Entry<Integer*, Integer*>* entry = new Entry<Integer*, Integer*>(arg1,
			arg2);
	printf("hashCode: <%d>\n", entry->hashCode());
	printf("key: <%d>\n", entry->getKey()->get());
	printf("value: <%d>\n", entry->getValue()->get());

	ret = ret + assertEquals(0, entry->hashCode());
	ret = ret + assertEquals(1, entry->getKey()->get());
	ret = ret + assertEquals(2, entry->getValue()->get());

	delete entry;
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}
