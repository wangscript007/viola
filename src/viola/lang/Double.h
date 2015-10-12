/*
 * Double.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_DOUBLE_H_
#define VIOLA_LANG_DOUBLE_H_

#include <bitset>

#include "Object.h"

using namespace std;

class Double: public Object {
private:
	double value;

public:
	Double(double value);
	~Double();

	double get();
	unsigned long doubleToLongBits();

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* VIOLA_LANG_DOUBLE_H_ */
