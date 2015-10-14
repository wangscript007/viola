/*
 * Long.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_LONG_H_
#define VIOLA_LANG_LONG_H_

#include "Object.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class Long: public Object {
private:
	long value;
public:
	Long(long value);
	~Long();

	long get();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);
	bool equals(Long* obj);

	bool equals(object obj);
	bool equals(long arg);

	//Override
	string toString();

	//Override
	string getClassName();
};

#endif /* VIOLA_LANG_LONG_H_ */
