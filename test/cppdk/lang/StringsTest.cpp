/*
 * StringsTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include <string>
#include "Strings.h"

int main() {
	std::string s = "foobar";
	Strings* str = new Strings(s);
	str->append(str);

	delete str;
	return 0;
}
