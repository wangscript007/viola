/*
 * StringsTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include <string>
#include <cassert>
#include "Strings.h"

int append() {
	int ret = 0;
	std::string s = "foobar";

	Strings* str = new Strings();
	str->append(s);
	printf("str: <%s>\n", str->toString().c_str());
	ret = ret + !str->equals("foobar");
	ret = ret + str->equals("notsame");

	delete str;
	return ret;
}

int isEmpty() {
	int ret = 0;
	std::string s = "foobar";

	Strings* str = new Strings();
	printf("bool: <%d>\n", str->isEmpty());
	ret = ret + !str->isEmpty();

	str->append(s);
	printf("bool: <%d>\n", str->isEmpty());
	ret = ret + str->isEmpty();

	delete str;

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + append();
	ret = ret + isEmpty();

	return ret;
}

