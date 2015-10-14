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
#include "EntrySet.h"

using namespace std;
typedef std::shared_ptr<Object> object;
typedef std::shared_ptr<Entry> entry;

class HashMap: public Object {
private:
	entry* table;
	int capacity;
	int threshold;

public:
	HashMap();
	HashMap(int capacity);
	~HashMap();

	bool containsKey(object key);
	bool containsValue(object value);

	object put(object key, object value);
	object putIfAbsent(object key, object value);
	object get(object key);
	object remove(object key);

	EntrySet entrySet();

	void clear();
	int size();
	int getCapacity();
	bool isEmpty();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);

	//Override
	string toString();

	//Override
	string getClassName();

private:
	int hash(int keyHashCode);
	int tableSizeFor(int capacity);
	void resize();
};

#endif /* VIOLA_UTIL_HASHMAP_H_ */
