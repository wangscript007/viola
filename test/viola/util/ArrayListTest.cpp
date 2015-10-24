/*
 * ArrayListTest.cpp
 *
 *  Created on: 2015/10/10
 *      Author: tsubaki
 */

#include "viola.h"

void dump(_ArrayList list) {
	std::string str = "[dump] ";
	str.append("class: " + list->getClassName() + ", ");
	str.append("hash: " + Integer(list->hashCode()).toString() + ".");
	System::out::println(str);
	System::out::println("[dump] " + list->toString() + ".");
}

int hashCode() {
	int ret = 0;

	_ArrayList list = std::make_shared<ArrayList>();
	{
		_Integer arg1 = std::make_shared<Integer>(1234);
		_Integer arg2 = std::make_shared<Integer>(5678);
		list->add(arg1);
		list->add(arg2);

		dump(list);
	}

	list->clear();

	dump(list);
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + hashCode();

	return ret;
}

