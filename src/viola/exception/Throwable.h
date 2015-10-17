/*
 * Throwable.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_THROWABLE_H_
#define VIOLA_LANG_THROWABLE_H_

#include "Object.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class Throwable: public Object {
protected:
	string message;
	Throwable* cause;
public:
	Throwable();
	Throwable(string message);
	Throwable(string message, Throwable* cause);
	virtual ~Throwable();

	string getMessage();
	Throwable* getCause();

	virtual string getClassName();
	virtual string toString();
};

#endif /* VIOLA_LANG_THROWABLE_H_ */
