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
#include "Strings.h"
#include "Entry.h"
#include "EntrySet.h"

typedef std::shared_ptr<Object> object;
typedef std::shared_ptr<Entry> entry;

class HashMap: public Object {
private:
	entry* table;
	int capacity;
	int threshold;
	int maxCapacity = 1 << 30;

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
	int getThreshold();
	int getCapacity();
	bool isEmpty();

	std::string toString(entry* e, int capacity);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();

private:
	int hash(int keyHashCode);
	int tableSizeFor(int capacity);
	entry* resize();
};

#endif /* VIOLA_UTIL_HASHMAP_H_ */
