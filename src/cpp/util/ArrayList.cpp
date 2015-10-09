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

void ArrayList::add(Object* obj) {
	list.push_back(obj->incrementReference());
}

Object* ArrayList::get(int i) {
	if (size() <= i) {
		return NULL;
	}

	std::list<Object*>::iterator it = list.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}
	Object* obj = *it;
	return obj->incrementReference();
}

void ArrayList::clear() {
	while (!this->isEmpty()) {
		Object* obj = list.front();
		Object::tryDelete(obj);
		list.pop_front();
	}
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

std::string ArrayList::getClassName() {
	return "ArrayList";
}
