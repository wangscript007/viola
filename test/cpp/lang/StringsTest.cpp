/*
 * StringsTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "../../../src/cpp/lang/Strings.h"

#include <string>
#include <cassert>

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

int hashCode() {
	int ret = 0;
	Strings* str = new Strings();
	printf("hashCode: <%d>\n", str->hashCode());
	ret = ret + str->hashCode();

	str->append("foobar");
	printf("hashCode: <%d>\n", str->hashCode());
	if (str->hashCode() == 0) {
		ret = ret + 1;
	}

	delete str;
	return ret;
}

int main() {
	int ret = 0;
	ret = ret + append();
	ret = ret + isEmpty();
	ret = ret + hashCode();
	return ret;
}

