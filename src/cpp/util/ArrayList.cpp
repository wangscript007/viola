/*
 * ArrayList.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "ArrayList.h"

ArrayList::ArrayList() {

}
ArrayList::~ArrayList() {
	this->clear();
}

void ArrayList::add(object obj) {
	list.push_back(obj);
}

object ArrayList::get(int i) {
	if (size() <= i) {
		return NULL;
	}

	std::list<object>::iterator it;
	it = list.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}

	object obj = *it;
	return obj;
}

void ArrayList::clear() {
	list.clear();
}

int ArrayList::size() {
	return list.size();
}

bool ArrayList::isEmpty() {
	return list.empty();
}

/*
 int hashCode = 1;
 for (E e : list)
 hashCode = 31*hashCode + (e==null ? 0 : e.hashCode());
 */
int ArrayList::hashCode() {
	int hashCode = 1;

	std::list<object>::iterator it;
	it = list.begin();
	for (int j = 0; j < list.size(); j++) {
		object obj = *it;
		int tmp = 0;
		if (obj.get() != NULL) {
			tmp = obj.get()->hashCode();
		}
		hashCode = 31 * hashCode + tmp;
	}
	return hashCode;
}

string ArrayList::getClassName() {
	return "ArrayList";
}
