/*
 * HashMap.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_UTIL_HASHMAP_H_
#define VIOLA_UTIL_HASHMAP_H_

#include <vector>
#include "Object.h"
#include "Entry.h"
#include "HashSet.h"

using namespace std;
typedef std::shared_ptr<Object> object;
typedef std::shared_ptr<Entry> entry;

class HashMap: public Object {
private:
	vector<entry> vector;
public:
	HashMap();
	~HashMap();

	bool containsKey(object key);
	bool containsValue(object value);

	object put(object key, object value);
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

#endif /* VIOLA_UTIL_HASHMAP_H_ */
