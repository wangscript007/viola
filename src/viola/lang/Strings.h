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

typedef std::shared_ptr<Object> object;

class Strings: public Object {

private:
	std::string internal;

public:
	Strings();
	Strings(std::string str);
	~Strings();

	void append(std::string str);
	bool contains(std::string str);
	std::string replace(std::string target, std::string replacement);

	bool startWith(std::string prefix);
	bool endWith(std::string suffix);

	int length();
	bool isEmpty();

	bool equalsIgnoreCase(std::string str);

	bool equals(Strings* str);
	bool equals(object obj);
	bool equals(std::string str);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};

#endif /* VIOLA_LANG_STRINGS_H_ */
