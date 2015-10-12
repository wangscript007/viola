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
typedef std::shared_ptr<Object> object;

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
	bool equals(Object* obj);
	bool equals(Double* obj);

	bool equals(object obj);
	bool equals(double arg);

	//Override
	string getClassName();

};

#endif /* VIOLA_LANG_DOUBLE_H_ */
