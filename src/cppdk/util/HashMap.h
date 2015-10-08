/*
 * HashMap.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPPDK_UTIL_HASHMAP_H_
#define CPPDK_UTIL_HASHMAP_H_

#include <vector>
#include "Entry.h"

template<class K, class V>
class HashMap {
private:
	std::vector<Entry<K, V>*> map;
public:
	HashMap() {
	}
	;
	virtual ~HashMap() {
		while (!map.empty()) {
			Entry<K, V>* entry = map.back();
			delete entry;
			map.pop_back();
		}
		map.clear();
	}
	;

	void put(K key, V value) {
		Entry<K, V>* entry = new Entry<K, V>(key, value);
		map.push_back(entry);
	}
	;

	V get(K key) {
		int i = 0;
		while (i < map.size()) {
			Entry<K, V>* entry = map.at(i);
			if (entry->getKey() == key) {
				return entry->getValue();
			}
			i++;
		}
		V ret = NULL;
		return ret;
	}
	;

	V remove(K key);

	void clear() {
		map.clear();
	}
	;
	int size() {
		return map.size();
	}
};

#endif /* CPPDK_UTIL_HASHMAP_H_ */
