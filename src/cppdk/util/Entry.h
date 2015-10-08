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
public:

	Entry(K key, V value) {

	}
	;
	virtual ~Entry() {

	}
	;

	K getKey();
	V getValue();

	int hashCode();

};

#endif /* CPPDK_UTIL_ENTRY_H_ */
