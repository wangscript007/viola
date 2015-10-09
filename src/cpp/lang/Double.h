/*
 * Double.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_LANG_DOUBLE_H_
#define CPP_LANG_DOUBLE_H_

#include "Object.h"

class Double: public Object {
private:
	double value;
public:
	Double(double value);
	virtual ~Double();

	double get();

	//Override
	int hashCode();
};

#endif /* CPP_LANG_DOUBLE_H_ */
