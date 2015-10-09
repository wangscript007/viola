/*
 * HashMap.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "HashMap.h"

HashMap::HashMap() {
}

HashMap::~HashMap() {
	this->clear();
}

void HashMap::put(Object* key, Object* value) {
	Entry* entry = new Entry(key, value);
	int hashCode = entry->hashCode();

	//TODO not hash.
	int i = 0;
	while (i < map.size()) {
		Entry* old = map.at(i);
		if (old->hashCode() == hashCode) {
			map.erase(map.begin() + i);
			Object::tryDelete(old);
			break;
		}
		i++;
	}

	map.push_back(entry);
}

Object* HashMap::get(Object* key) {

	//TODO not hash.
	int i = 0;
	while (i < map.size()) {
		Entry* entry = map.at(i);
		if (entry->getKey()->hashCode() == key->hashCode()) {
			entry->getValue()->incrementReference();
			return entry->getValue();
		}
		i++;
	}
	return NULL;

}

void HashMap::clear() {
	while (!map.empty()) {
		Entry* entry = map.back();
		Object::tryDelete(entry);
		map.pop_back();
	}
	map.clear();
}

int HashMap::size() {
	return map.size();
}
