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
//typedef std::shared_ptr<Object> object;
//typedef std::shared_ptr<Integer> integer;

template<class T>
class ArrayList: public Object {
private:
	std::list<T> list;
public:
	ArrayList<T>() {
	}
	;
	~ArrayList() {
		list.clear();
	}
	;

	void add(T obj) {
		list.push_back(obj);
	}
	;
	T get(int i) {
		if (size() <= i) {
			return NULL;
		}

		typename std::list<T>::iterator it;
		it = list.begin();
		for (int j = 0; j < i; j++) {
			it++;
		}

		T obj = *it;
		return obj;
	}
	;

	void clear() {
		list.clear();
	}
	;
	int size() {
		return list.size();
	}
	;
	bool isEmpty() {
		return list.empty();
	}
	;

	//Override
	int hashCode() {
		return 0;
	}
	;

	//Override
	string getClassName() {
		return "ArrayList";
	}
	;

};

#endif /* CPP_UTIL_ARRAYLIST_H_ */
