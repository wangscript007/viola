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
	map.push_back(entry);
}

Object* HashMap::get(Object* key) {
	int i = 0;
	while (i < map.size()) {
		Entry* entry = map.at(i);
		if (entry->getKey() == key) {
			return entry->getValue();
		}
		i++;
	}
	return NULL;

}

void HashMap::clear() {
	while (!map.empty()) {
		Entry* entry = map.back();
		delete entry;
		map.pop_back();
	}
	map.clear();
}

int HashMap::size() {
	return map.size();
}
