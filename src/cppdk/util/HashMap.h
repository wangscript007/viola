/*
 * HashMap.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPPDK_UTIL_HASHMAP_H_
#define CPPDK_UTIL_HASHMAP_H_

template<class K, class V>
class HashMap {
public:
	HashMap();
	virtual ~HashMap();

	void put(K key, V value);
	V get(K key);
	V remove(K key);

	void clear();
	int size();
};

#endif /* CPPDK_UTIL_HASHMAP_H_ */
