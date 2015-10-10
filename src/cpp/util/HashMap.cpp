/*
 * HashMap.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "HashMap.h"
#include "Integer.h"

HashMap::HashMap() {
}

HashMap::~HashMap() {
	this->clear();
}

void HashMap::put(Object key, Object value) {
	Entry entry(key, value);
	int hashCode = entry.hashCode();

	//TODO not hash.
	int i = 0;
	while (i < map.size()) {
		Entry* old = map.at(i).get();
		if (old->hashCode() == hashCode) {
			map.erase(map.begin() + i);
			break;
		}
		i++;
	}

	map.push_back(std::make_shared<Entry>(entry));
}

Object* HashMap::get(Object key) {

	//TODO not hash.
	int i = 0;
	while (i < map.size()) {
		Entry* entry = map.at(i).get();
		int storedHashCode = entry->getKey()->hashCode();

		if (storedHashCode == key.hashCode()) {
			return entry->getValue();
		}
		i++;
	}
	return NULL;

}

void HashMap::clear() {
	map.clear();
}

int HashMap::size() {
	return map.size();
}

bool HashMap::isEmpty() {
	return map.empty();
}

int HashMap::hashCode() {
	return 0;
}

std::string HashMap::getClassName() {
	return "HashMap";
}
