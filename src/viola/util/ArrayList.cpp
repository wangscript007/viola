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

void ArrayList::add(std::shared_ptr<Object> obj) {
	list.push_back(obj);
}

std::shared_ptr<Object> ArrayList::get(int i) {
	if (size() <= i) {
		return NULL;
	}

	std::list<std::shared_ptr<Object> >::iterator it = list.begin();
	for (int j = 0; j < i; j++) {
		it++;
	}

	std::shared_ptr<Object> obj = *it;
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
 * int hashCode = 1;
 * for (E e : list)
 * hashCode = 31*hashCode + (e==null ? 0 : e.hashCode());
 */
int ArrayList::hashCode() {
	int hashCode = 1;

	std::list<std::shared_ptr<Object> >::iterator it = list.begin();
	for (int i = 0; i < list.size(); i++) {
		std::shared_ptr<Object> obj = *it;
		int tmp = 0;
		if (obj.get() != NULL) {
			tmp = obj.get()->hashCode();
		}
		hashCode = 31 * hashCode + tmp;
		i++;
	}
	return hashCode;
}

bool ArrayList::equals(Object* obj) {
	ArrayList* list = (ArrayList*) obj;
	if (hashCode() == list->hashCode()) {
		return true;
	}
	return false;
}

//Override
std::string ArrayList::toString() {
	std::string str("ArrayList[");
	for (int i = 0; i < size(); i++) {
		str.append(this->get(i)->toString());
		if (i < size() - 1) {
			str.append(", ");
		}
	}
	str.append("]");
	return str;
}

std::string ArrayList::getClassName() {
	return "ArrayList";
}
