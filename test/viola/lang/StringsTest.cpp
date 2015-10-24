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
	System::out::println("empty: " + Boolean(str->isEmpty()).toString());
	ret = ret + !str->isEmpty();

	str->append("hoge");
	System::out::println("empty: " + Boolean(str->isEmpty()).toString());
	ret = ret + str->isEmpty();

	return ret;
}

int hashCodeTest() {
	int ret = 0;

	_Strings str = std::make_shared<Strings>();
	ret = ret + str->hashCode();

	str->append("foobar");
	if (str->hashCode() == 0) {
		ret = ret + 1;
	}

	return ret;
}

int equalsTest() {
	int ret = 0;
	std::string s = "foobar";

	_Strings str = std::make_shared<Strings>();

	str->append(s);
	System::out::println("str: " + str->toString());

	bool bool1 = str->equals("foobar");
	bool bool2 = str->equals("notsame");

	System::out::println("foobar.eq(foobar): " + Boolean(bool1).toString());
	System::out::println("foobar.eq(notsame): " + Boolean(bool2).toString());

	ret = ret + !bool1;
	ret = ret + bool2;

	_Strings str2 = std::make_shared<Strings>("foobar");
	bool bool3 = str2->equals(str);
	System::out::println("foobar.eq(foobar): " + Boolean(bool3).toString());

	ret = ret + Assert::assertEquals(str, str);
	ret = ret + Assert::assertEquals(str, str2);

	return ret;
}

int main() {
	int ret = 0;
	ret = ret + isEmptyTest();
	ret = ret + hashCodeTest();
	ret = ret + equalsTest();
	return ret;
}

