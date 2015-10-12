/*
 * HashMap.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include "HashMap.h"

HashMap::HashMap() {
}

HashMap::~HashMap() {
	this->clear();
}

bool HashMap::containsKey(object key) {
	std::vector<entry>::iterator it;
	it = vector.begin();
	for (int i = 0; i < size(); i++) {
		entry entry = *it;
		object obj = entry.get()->getKey();
		if (obj.get()->hashCode() == key.get()->hashCode()) {
			return true;
		}
		it++;
	}
	return false;
}

object HashMap::put(object key, object value) {
	object ret = this->remove(key);
	entry entry = std::make_shared<Entry>(key, value);
	vector.push_back(entry);
	return ret;
}

object HashMap::putIfAbsent(object key, object value) {
	if (this->containsKey(key)) {
		return this->get(key);
	}
	put(key, value);
	return NULL;
}

object HashMap::get(object key) {
	std::vector<entry>::iterator it;
	it = vector.begin();
	for (int i = 0; i < size(); i++) {
		entry entry = *it;
		object obj = entry.get()->getKey();
		if (obj.get()->hashCode() == key.get()->hashCode()) {
			return entry->getValue();
		}
		it++;
	}

	return NULL;

}
object HashMap::remove(object key) {
	std::vector<entry>::iterator it;
	it = vector.begin();

	for (int i = 0; i < size(); i++) {
		entry entry = *it;
		object obj = entry.get()->getKey();
		if (obj.get()->hashCode() == key.get()->hashCode()) {
			vector.erase(it);
			return entry;
		}
		it++;
	}

	return NULL;
}

void HashMap::clear() {
	vector.clear();
}
int HashMap::size() {
	return vector.size();
}
bool HashMap::isEmpty() {
	return vector.empty();
}

int HashMap::hashCode() {
	int hashCode = 1;

	std::vector<entry>::iterator it;
	it = vector.begin();
	for (int i = 0; i < size(); i++) {
		entry entry = *it;
		Entry* entryp = entry.get();
		int tmp = 0;
		if (entryp != NULL) {
			tmp = entryp->hashCode();
		}
		hashCode = 31 * hashCode + tmp;
		i++;
	}
	return hashCode;
}

bool HashMap::equals(Object* obj) {
	HashMap* map = (HashMap*) obj;
	if (hashCode() == map->hashCode()) {
		return true;
	}
	return false;
}

string HashMap::getClassName() {
	return "HashMap";
}
