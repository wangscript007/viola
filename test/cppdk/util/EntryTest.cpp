/*
 * EntryTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include <string>
#include "Entry.h"

int hashCodeTest() {
	Entry<int, int> entry(1, 1);
//	printf("hashCode: <%d>\n", entry.hashCode());

//	delete entry;
	return 0;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}
