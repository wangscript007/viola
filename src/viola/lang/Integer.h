/*
 * Integer.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_INTEGER_H_
#define VIOLA_LANG_INTEGER_H_

#include "Object.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class Integer: public Object {
private:
	int i;
public:
	Integer(int value);
	~Integer();

	int get();

	//Override
	int hashCode();

	//Override
	bool equals(Object* obj);
	bool equals(Integer* obj);

	bool equals(object obj);
	bool equals(int arg);

	//Override
	string toString();

	//Override
	string getClassName();

};

#endif /* VIOLA_LANG_INTEGER_H_ */
