/*
 * EntryTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Integer.h"
#include "Entry.h"
#include "Assert.h"

typedef std::shared_ptr<Object> object;
typedef std::shared_ptr<Integer> integer;

int hashCodeTest() {
	int ret = 0;

	integer arg1 = std::make_shared<Integer>(1234);
	integer arg2 = std::make_shared<Integer>(5678);
	Entry entry(arg1, arg2);
	printf("className: <%s>\n", entry.getClassName().c_str());

	object obj1 = entry.getKey();
	object obj2 = entry.getValue();

	Integer* key = (Integer*) obj1.get();
	Integer* value = (Integer*) obj2.get();
	printf("key: <%d>\n", key->get());
	printf("value: <%d>\n", value->get());
	printf("hashCode: <%d>\n", entry.hashCode());

	ret = ret + Assert::assertEquals(1234, key->get());
	ret = ret + Assert::assertEquals(5678, value->get());
	ret = ret + Assert::assertEquals(4860, entry.hashCode());

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCodeTest();

	return ret;
}
