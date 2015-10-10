/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_ENTRY_H_
#define CPP_UTIL_ENTRY_H_

#include "Object.h"

class Entry: public Object {
private:
	std::shared_ptr<Object> key;
	std::shared_ptr<Object> value;
public:

	Entry(Object key, Object value);

	virtual ~Entry();

	Object* getKey();
	Object* getValue();

	//Override
	int hashCode();

	//Override
	std::string getClassName();

};

#endif /* CPP_UTIL_ENTRY_H_ */
