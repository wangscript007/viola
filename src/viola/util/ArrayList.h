/*
 * ArrayList.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef VIOLA_UTIL_ARRAYLIST_H_
#define VIOLA_UTIL_ARRAYLIST_H_

#include <list>
#include "Object.h"

typedef std::shared_ptr<Object> object;

class ArrayList: public Object {
private:
	std::list<object> list;
public:
	ArrayList();
	~ArrayList();

	void add(object obj);
	object get(int i);

	void clear();
	int size();
	bool isEmpty();

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();

};

#endif /* VIOLA_UTIL_ARRAYLIST_H_ */
