/*
 * StringsTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "viola.h"

int isEmptyTest() {
	int ret = 0;

	_Strings str = std::make_shared<Strings>();
	printf("bool: <%d>\n", str->isEmpty());
	ret = ret + !str->isEmpty();

	str->append("hoge");
	printf("bool: <%d>\n", str->isEmpty());
	ret = ret + str->isEmpty();

	return ret;
}

int hashCodeTest() {
	int ret = 0;

	_Strings str = std::make_shared<Strings>();
	printf("hashCode: <%d>\n", str->hashCode());
	ret = ret + str->hashCode();

	str->append("foobar");
	printf("hashCode: <%d>\n", str->hashCode());
	if (str->hashCode() == 0) {
		ret = ret + 1;
	}

	return ret;
}

int equalsTest() {
	int ret = 0;
	std::string s = "foobar";

	_Strings str = std::make_shared<Strings>();
	printf("className: <%s>\n", str->toChar());

	str->append(s);
	printf("str: <%s>\n", str->toChar());
	printf("hashCode: <%d>\n", str->hashCode());

	bool bool1 = str->equals("foobar");
	bool bool2 = str->equals("notsame");

	printf("foobar->equals(foobar): <%d>\n", bool1);
	printf("foobar->equals(notsame): <%d>\n", bool2);

	ret = ret + !bool1;
	ret = ret + bool2;

	_Strings str2 = std::make_shared<Strings>();
	printf("foobar->equals(foobar): <%d>\n", str->equals(str2));

	ret = ret + Assert::assertEquals(str, str);
	ret = ret + !Assert::assertEquals(str, str2);

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + isEmptyTest();
	ret = ret + hashCodeTest();
	ret = ret + equalsTest();
	return ret;
}

