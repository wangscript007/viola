/*
 * ArrayList.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#pragma once
#include <list>
#include "Object.h"

class ArrayList: public Object {
private:
	std::list<std::shared_ptr<Object>> list;
public:
	ArrayList();
	~ArrayList();

	void add(std::shared_ptr<Object> obj);
	std::shared_ptr<Object> get(uint32_t i);

	void clear();
	uint32_t size();
	bool isEmpty();

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();

};
