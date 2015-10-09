/*
 * Integer.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_LANG_INTEGER_H_
#define CPP_LANG_INTEGER_H_

#include "../../cpp/lang/Object.h"

class Integer: public Object {
private:
	int i;
public:
	Integer(int i);
	Integer();
	virtual ~Integer();

	int get();

	//Override
	int hashCode();
};

#endif /* CPP_LANG_INTEGER_H_ */
