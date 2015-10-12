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

	//Override
	bool equals(string str);
	bool equalsIgnoreCase(string str);

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* VIOLA_LANG_STRINGS_H_ */
