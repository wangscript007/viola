/*
 * HashSet.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_UTIL_HASHSET_H_
#define CPP_UTIL_HASHSET_H_

#include "Object.h"

class HashSet: public Object {
public:
	HashSet();
	virtual ~HashSet();

	//Override
	int hashCode();

	//Override
	std::string getClassName();
};

#endif /* CPP_UTIL_HASHSET_H_ */
