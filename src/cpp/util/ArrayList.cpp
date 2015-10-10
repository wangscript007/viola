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

void ArrayList::add(Object obj) {
	list.push_back(std::make_shared<Object>(obj));
}

Object* ArrayList::get(int i) {
	if (size() <= i) {
		return NULL;
	}

	std::list<std::shared_ptr<Object>>::iterator it = list.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}
	std::shared_ptr<Object> obj = *it;
	return obj.get();
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

std::string ArrayList::getClassName() {
	return "ArrayList";
}
