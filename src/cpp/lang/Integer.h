/*
 * Integer.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_LANG_INTEGER_H_
#define CPP_LANG_INTEGER_H_

#include "Object.h"

using namespace std;

class Integer: public Object {
private:
	int i = 0;
public:
	Integer(int value);
	~Integer();

	int get();

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* CPP_LANG_INTEGER_H_ */
