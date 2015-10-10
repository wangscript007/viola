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

typedef std::shared_ptr<Object> object;

class ArrayList: public Object {
private:
	std::list<object> list;
public:
	ArrayList();
	virtual ~ArrayList();

	void add(object obj);
	object get(int i);

	void clear();
	int size();
	bool isEmpty();

	//Override
	int hashCode();

	//Override
	std::string getClassName();

};

#endif /* CPP_UTIL_ARRAYLIST_H_ */
