/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef VIOLA_UTIL_ENTRY_H_
#define VIOLA_UTIL_ENTRY_H_

#include "Object.h"
using namespace std;
typedef std::shared_ptr<Object> object;

//template<class T>
class Entry: public Object {
private:
	object key;
	object value;
public:

	Entry(object key, object value);
	~Entry();

	object getKey();
	object getValue();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);

	//Override
	string getClassName();

};

#endif /* VIOLA_UTIL_ENTRY_H_ */
