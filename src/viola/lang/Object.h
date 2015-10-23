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

class Object {

public:
	Object();
	virtual ~Object();

	virtual int hashCode();
	virtual bool equals(Object* obj);
	virtual std::string getClassName();
	virtual std::string toString();
	const char* toChar();
};

#endif /* VIOLA_LANG_OBJECT_H_ */
