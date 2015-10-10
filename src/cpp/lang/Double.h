/*
 * Double.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_LANG_DOUBLE_H_
#define CPP_LANG_DOUBLE_H_

#include "Object.h"

using namespace std;

class Double: public Object {
private:
	double value;
public:
	Double(double value);
	~Double();

	double get();

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* CPP_LANG_DOUBLE_H_ */
