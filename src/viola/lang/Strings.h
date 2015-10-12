/*
 * String.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_STRINGS_H_
#define VIOLA_LANG_STRINGS_H_

#include <string>
#include "Object.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class Strings: public Object {

private:
	string internal;

public:
	Strings();
	Strings(string str);
	~Strings();

	void append(string str);
	bool contains(string str);
	string replace(string target, string replacement);

	bool startWith(string prefix);
	bool endWith(string suffix);

	int length();
	bool isEmpty();
	string toString();

	bool equalsIgnoreCase(string str);

	//Override
	bool equals(Object* obj);
	bool equals(Strings* str);

	bool equals(object obj);
	bool equals(string str);

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* VIOLA_LANG_STRINGS_H_ */
