/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Entry: public Object {
private:
	std::shared_ptr<Object> key;
	std::shared_ptr<Object> value;
	std::shared_ptr<Object> next;
public:
	Entry(std::shared_ptr<Object> key, std::shared_ptr<Object> value);
	Entry(Entry* e);
	~Entry();

	std::shared_ptr<Object> getKey();
	void setKey(std::shared_ptr<Object> key);

	std::shared_ptr<Object> getValue();
	void setValue(std::shared_ptr<Object> value);

	std::shared_ptr<Object> getNext();
	void setNext(std::shared_ptr<Object> next);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();
};
