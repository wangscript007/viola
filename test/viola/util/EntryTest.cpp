/*
 * EntryTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "viola.h"

void dump(Entry* entry) {
	std::string str = "[dump] ";
	str.append("class: " + entry->getClassName() + ", ");
	str.append("hash: " + Integer(entry->hashCode()).toString() + ", ");
	str.append("key: " + entry->getKey()->toString() + ", ");
	str.append("val: " + entry->getValue()->toString() + ".");
	System::out::println(str);
	System::out::println("[dump] " + entry->toString() + ".");
}

int hashCode() {
	int ret = 0;

	_Integer arg1 = std::make_shared<Integer>(1234);
	_Integer arg2 = std::make_shared<Integer>(5678);
	_Integer arg3 = std::make_shared<Integer>(9012);

	Entry entry1(arg1, arg2);
	Entry entry2(arg1, arg3);

	dump(&entry1);
	dump(&entry2);

	return ret;
}

int getset() {
	int ret = 0;

	_Integer arg1 = std::make_shared<Integer>(1234);
	_Integer arg2 = std::make_shared<Integer>(5678);
	Entry entry(arg1, arg2);
	dump(&entry);

	_Object obj1 = entry.getKey();
	_Object obj2 = entry.getValue();

	Integer* key = (Integer*) obj1.get();
	Integer* value = (Integer*) obj2.get();

	ret = ret + Assert::assertEquals(1234, key->get());
	ret = ret + Assert::assertEquals(5678, value->get());

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCode();
	ret = ret + getset();

	return ret;
}
