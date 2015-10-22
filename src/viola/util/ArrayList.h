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

class ArrayList: public Object {
private:
	std::list<std::shared_ptr<Object>> list;
public:
	ArrayList();
	~ArrayList();

	void add(std::shared_ptr<Object> obj);
	std::shared_ptr<Object> get(int i);

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
