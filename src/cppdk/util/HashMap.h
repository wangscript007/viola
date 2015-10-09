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

class HashMap {
private:
	std::vector<Entry*> map;
public:
	HashMap();
	virtual ~HashMap();

	void put(Object* key, Object* value);
	Object* get(Object* key);
	Object* remove(Object* key);

	void clear();
	int size();

};

#endif /* CPPDK_UTIL_HASHMAP_H_ */
