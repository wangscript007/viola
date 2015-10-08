/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPPDK_UTIL_ENTRY_H_
#define CPPDK_UTIL_ENTRY_H_

template<class K, class V>
class Entry {
public:
	Entry();
	virtual ~Entry();

	K getKey();
	V getValue();

	int hashCode();
};

#endif /* CPPDK_UTIL_ENTRY_H_ */
