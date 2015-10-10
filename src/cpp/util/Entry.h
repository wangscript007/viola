/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_ENTRY_H_
#define CPP_UTIL_ENTRY_H_

#include "Object.h"

typedef std::shared_ptr<Object> object;

class Entry: public Object {
private:
	object key;
	object value;
public:

	Entry(object key, object value);
	virtual ~Entry();

	object getKey();
	object getValue();

	//Override
	int hashCode();

	//Override
	std::string getClassName();

};

#endif /* CPP_UTIL_ENTRY_H_ */
