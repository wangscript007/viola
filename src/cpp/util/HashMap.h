/*
 * HashMap.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_HASHMAP_H_
#define CPP_UTIL_HASHMAP_H_

#include "Object.h"
#include "HashSet.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class HashMap: public Object {
public:
	HashMap();
	~HashMap();

	bool containsKey(object key);
	bool containsValue(object value);

	void put(object key, object value);
	object putIfAbsent(object key, object value);
	object get(object key);
	object remove(object key);

	HashSet entrySet();
	HashSet keySet();
	HashSet values();

	void clear();
	int size();
	bool isEmpty();

	//Override
	int hashCode();

	//Override
	string getClassName();
};

#endif /* CPP_UTIL_HASHMAP_H_ */
