/*
 * Object.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_OBJECT_H_
#define VIOLA_LANG_OBJECT_H_

#include <string>
#include <memory>
#include <limits.h>

using namespace std;

class Object {

public:
	Object();
	virtual ~Object();

	virtual int hashCode();
	virtual bool equals(Object* obj);
	virtual string getClassName();
	virtual string toString();
};

#endif /* VIOLA_LANG_OBJECT_H_ */
