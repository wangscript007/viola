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
		it++;
		entry entry = *it;
		Entry* entryp = entry.get();
		if (entryp->getKey()->hashCode() == key->hashCode()) {
			return true;
		}
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
		it++;
		entry entry = *it;
		Entry* entryp = entry.get();
		if (entryp->getKey()->hashCode() == key->hashCode()) {
			return entry->getValue();
		}
	}

	return NULL;

}
object HashMap::remove(object key) {
	std::vector<entry>::iterator it;
	it = vector.begin();
	for (int i = 0; i < size(); i++) {
		it++;
		entry entry = *it;
		Entry* entryp = entry.get();
		if (entryp->getKey()->hashCode() == key->hashCode()) {
			vector.erase(it);
			return entry;
		}
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
	return 0;
}

string HashMap::getClassName() {
	return "HashMap";
}
