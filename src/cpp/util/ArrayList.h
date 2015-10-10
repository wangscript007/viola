/*
 * ArrayList.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_ARRAYLIST_H_
#define CPP_UTIL_ARRAYLIST_H_

#include <list>
#include "Object.h"

class ArrayList: public Object {
private:
	std::list<std::shared_ptr<Object>> list;
public:
	ArrayList();
	virtual ~ArrayList();

	void add(Object obj);
	Object* get(int i);

	void clear();
	int size();
	bool isEmpty();

	//Override
	int hashCode();

	//Override
	std::string getClassName();

};

#endif /* CPP_UTIL_ARRAYLIST_H_ */