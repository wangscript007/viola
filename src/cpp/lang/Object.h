/*
 * Object.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_LANG_OBJECT_H_
#define CPP_LANG_OBJECT_H_

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <memory>

using namespace std;

class Object {

public:
	Object();
	virtual ~Object();

	bool equals(Object* obj);
	int hashCode();
	string getClassName();
};

#endif /* CPP_LANG_OBJECT_H_ */
