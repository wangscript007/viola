/*
 * String.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef CPP_LANG_STRINGS_H_
#define CPP_LANG_STRINGS_H_

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
	bool endWith(string suffix);
	bool equals(string str);
	bool equalsIgnoreCase(string str);
	bool isEmpty();
	std::string replace(string target, string replacement);
	bool startWith(string prefix);
	std::string toString();
	int length();

	//Override
	int hashCode();

	//Override
	string getClassName();

};

#endif /* CPP_LANG_STRINGS_H_ */
