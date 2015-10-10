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
//#include "Integer.h"
using namespace std;
typedef std::shared_ptr<Object> object;
//typedef std::shared_ptr<Integer> integer;

//template<class T>
class ArrayList: public Object {
private:
	list<object> list;
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

	//Override
	string getClassName();

};

#endif /* CPP_UTIL_ARRAYLIST_H_ */
