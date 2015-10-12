/*
 * HashSet.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef VIOLA_UTIL_HASHSET_H_
#define VIOLA_UTIL_HASHSET_H_

#include "Object.h"

using namespace std;

class HashSet: public Object {
public:
	HashSet();
	~HashSet();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);

	//Override
	string getClassName();
};

#endif /* VIOLA_UTIL_HASHSET_H_ */
