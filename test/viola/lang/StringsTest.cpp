/*
 * StringsTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Strings.h"

int append() {
	int ret = 0;
	std::string s = "foobar";

	Strings str;
	printf("className: <%s>\n", str.getClassName().c_str());

	str.append(s);
	printf("str: <%s>\n", str.toString().c_str());
	printf("hashCode: <%d>\n", str.hashCode());

	bool bool1 = str.equals("foobar");
	bool bool2 = str.equals("notsame");
	printf("foobar->equals(foobar): <%d>\n", bool1);
	printf("foobar->equals(notsame): <%d>\n", bool2);

	ret = ret + !bool1;
	ret = ret + bool2;

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

	Strings str;
	printf("hashCode: <%d>\n", str.hashCode());
	ret = ret + str.hashCode();

	str.append("foobar");
	printf("hashCode: <%d>\n", str.hashCode());
	if (str.hashCode() == 0) {
		ret = ret + 1;
	}

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + append();
	ret = ret + isEmpty();
	ret = ret + hashCode();
	return ret;
}

