/*
 * String.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef CPPDK_LANG_STRINGS_H_
#define CPPDK_LANG_STRINGS_H_

#include <string>

class Strings {

private:
	std::string internal;

public:
	Strings();
	Strings(std::string str);
	~Strings();

	void append(std::string str);
	bool contains(std::string str);
	bool endWith(std::string suffix);
	bool equals(std::string str);
	bool equalsIgnoreCase(std::string str);
	bool isEmpty();
	std::string replace(std::string target, std::string replacement);
	bool startWith(std::string prefix);
	std::string toString();
};

#endif /* CPPDK_LANG_STRINGS_H_ */
