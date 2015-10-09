/*
 * HashMap.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_HASHMAP_H_
#define CPP_UTIL_HASHMAP_H_

#include <vector>

#include "../../cpp/util/Entry.h"

class HashMap: public Object {
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

#endif /* CPP_UTIL_HASHMAP_H_ */
