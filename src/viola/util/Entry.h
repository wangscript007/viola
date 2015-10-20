/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef VIOLA_UTIL_ENTRY_H_
#define VIOLA_UTIL_ENTRY_H_

#include "Object.h"

typedef std::shared_ptr<Object> object;

//template<class T>
class Entry: public Object {
private:
	object key;
	object value;
	object next;
public:

	Entry(object key, object value);
	Entry(Entry* e);
	~Entry();

	object getKey();

	object getValue();
	void setValue(object value);

	object getNext();
	void setNext(object next);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string toString();
	std::string getClassName();
};

#endif /* VIOLA_UTIL_ENTRY_H_ */
