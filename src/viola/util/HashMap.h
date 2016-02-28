/*
 * HashMap.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"
#include "Strings.h"
#include "Entry.h"
#include "EntrySet.h"

class HashMap: public Object {
private:
	std::shared_ptr<Entry>* table;
	uint32_t capacity;
	uint32_t threshold;
	uint32_t maxCapacity = 1 << 30;

public:
	HashMap();
	HashMap(uint32_t capacity);
	~HashMap();

	bool containsKey(std::shared_ptr<Object> key);
	bool containsValue(std::shared_ptr<Object> value);

	std::shared_ptr<Object> put(std::shared_ptr<Object> key,
			std::shared_ptr<Object> value);
	std::shared_ptr<Object> putIfAbsent(std::shared_ptr<Object> key,
			std::shared_ptr<Object> value);
	std::shared_ptr<Object> get(std::shared_ptr<Object> key);
	std::shared_ptr<Object> remove(std::shared_ptr<Object> key);

	std::shared_ptr<Object> put(std::string key, std::string value);
	std::shared_ptr<Object> get(std::string key);

	EntrySet entrySet();

	void clear();
	uint32_t size();
	uint32_t getThreshold();
	uint32_t getCapacity();
	bool isEmpty();

	std::string toString(std::shared_ptr<Entry>* e, uint32_t capacity);

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();

private:
	uint32_t hash(uint32_t keyHashCode);
	uint32_t tableSizeFor(uint32_t capacity);
	std::shared_ptr<Entry>* resize();
};
