/*
 * AssertTest.cpp
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	int ret = 0;

	ret = ret + Assert::assertEquals(1.2, 1.2);
	ret = ret + !Assert::assertEquals(1.2, 1.3);

	ret = ret + Assert::assertEquals(1, 1);
	ret = ret + !Assert::assertEquals(1, 2);

	ret = ret + Assert::assertEquals((long) 123, (long) 123);
	ret = ret + !Assert::assertEquals((long) 1, (long) 2);

	_Double d1 = std::make_shared<Double>(1.2);
	_Double d2 = std::make_shared<Double>(3.4);
	ret = ret + Assert::assertEquals(d1, d1);
	ret = ret + !Assert::assertEquals(d1, d2);

	_Integer i1 = std::make_shared<Integer>(1);
	_Integer i2 = std::make_shared<Integer>(2);
	ret = ret + Assert::assertEquals(i1, i1);
	ret = ret + !Assert::assertEquals(i1, i2);

	_Long l1 = std::make_shared<Long>(1);
	_Long l2 = std::make_shared<Long>(2);
	ret = ret + Assert::assertEquals(l1, l1);
	ret = ret + !Assert::assertEquals(l1, l2);

	_Strings s1 = std::make_shared<Strings>("foobar");
	_Strings s2 = std::make_shared<Strings>("hoge");
	ret = ret + Assert::assertEquals(s1, s1);
	ret = ret + !Assert::assertEquals(s1, s2);

	return ret;
}
