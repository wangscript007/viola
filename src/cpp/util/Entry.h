/*
 * Entry.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_ENTRY_H_
#define CPP_UTIL_ENTRY_H_

#include "../../cpp/lang/Object.h"

class Entry: public Object {
private:
	Object* key;
	Object* value;
public:

	Entry(Object* key, Object* value);

	virtual ~Entry();

	Object* getKey();
	Object* getValue();

	//Override
	int hashCode();

};

#endif /* CPP_UTIL_ENTRY_H_ */
