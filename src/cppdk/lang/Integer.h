/*
 * Integer.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPPDK_LANG_INTEGER_H_
#define CPPDK_LANG_INTEGER_H_

#include "Object.h"

class Integer: public Object {
private:
	int i;
public:
	Integer(int i);
	Integer();
	virtual ~Integer();

	int get();
};

#endif /* CPPDK_LANG_INTEGER_H_ */
