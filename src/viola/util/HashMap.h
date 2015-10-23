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

class HashMap: public Object {
private:
	std::shared_ptr<Entry>* table;
	int capacity;
	int threshold;
	int maxCapacity = 1 << 30;

public:
	HashMap();
	HashMap(int capacity);
	~HashMap();

	bool containsKey(std::shared_ptr<Object> key);
	bool containsValue(std::shared_ptr<Object> value);

	std::shared_ptr<Object> put(std::shared_ptr<Object> key,
			std::shared_ptr<Object> value);
	std::shared_ptr<Object> putIfAbsent(std::shared_ptr<Object> key,
			std::shared_ptr<Object> value);
	std::shared_ptr<Object> get(std::shared_ptr<Object> key);
	std::shared_ptr<Object> remove(std::shared_ptr<Object> key);

	EntrySet entrySet();

	void clear();
	int size();
	int getThreshold();
	int getCapacity();
	bool isEmpty();

	std::string toString(std::shared_ptr<Entry>* e, int capacity);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();


private:
	int hash(int keyHashCode);
	int tableSizeFor(int capacity);
	std::shared_ptr<Entry>* resize();
};

#endif /* VIOLA_UTIL_HASHMAP_H_ */
