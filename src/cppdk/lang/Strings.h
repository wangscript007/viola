/*
 * String.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#ifndef CPPDK_LANG_STRINGS_H_
#define CPPDK_LANG_STRINGS_H_

#include <string>
#include "Boolean.h"

class Strings {
public:
	Strings();
	Strings(std::string str);
	~Strings();

	void append(Strings str);
	Boolean contains(Strings str);
	Boolean endWith(Strings str);
	Boolean equals(Strings str);
	Boolean equalsIgnoreCase(Strings str);
	Boolean isEmpty();
	Strings replace(Strings target, Strings replacement);
	Boolean startWith(Strings str);
};

#endif /* CPPDK_LANG_STRINGS_H_ */
