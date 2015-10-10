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

	std::list<object>::iterator it = list.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}
	return *it;
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

int ArrayList::hashCode() {
	return 0;
}

string ArrayList::getClassName() {
	return "ArrayList";
}
