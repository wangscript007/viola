/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPPDK_UTIL_ENTRY_H_
#define CPPDK_UTIL_ENTRY_H_
#pragma once
#include "Object.h"

template<class K, class V>
class Entry {
private:
	K key;
	V value;
public:

	Entry(K key, V value) {
		this->key = key;
		this->value = value;
	}
	;

	virtual ~Entry() {
		delete key;
		delete value;
	}

	K getKey() {
		return key;
	}
	V getValue() {
		return value;
	}

	int hashCode() {
		return 0;
	}
	;

};

#endif /* CPPDK_UTIL_ENTRY_H_ */
