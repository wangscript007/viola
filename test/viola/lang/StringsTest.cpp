/*
 * StringsTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Strings.h"

int appendTest() {
	int ret = 0;
	std::string s = "foobar";

	Strings str;
	printf("className: <%s>\n", str.getClassName().c_str());

	str.append(s);
	printf("str: <%s>\n", str.toString().c_str());
	printf("hashCode: <%d>\n", str.hashCode());

	return ret;
}

int isEmptyTest() {
	int ret = 0;
	std::string s = "foobar";

	Strings str;
	printf("bool: <%d>\n", str.isEmpty());
	ret = ret + !str.isEmpty();

	str.append(s);
	printf("bool: <%d>\n", str.isEmpty());
	ret = ret + str.isEmpty();

	return ret;
}

int hashCodeTest() {
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

int equalsTest() {
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

	Strings* strp = new Strings("foobar");
	printf("foobar->equals(foobar): <%d>\n", str.equals(strp));
	delete strp;

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + appendTest();
	ret = ret + isEmptyTest();
	ret = ret + hashCodeTest();
	ret = ret + equalsTest();
	return ret;
}

