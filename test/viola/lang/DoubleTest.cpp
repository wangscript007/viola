/*
 * DoubleTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "viola.h"

int main() {
	int ret = 0;

	_Double d1 = std::make_shared<Double>(1.2);
	_Double d2 = std::make_shared<Double>(3.4);

	System::out::println("d1.class: " + d1->getClassName());
	System::out::println("d1.long: " + Long(d1->doubleToLongBits()).toString());
	System::out::println("d2.long: " + Long(d2->doubleToLongBits()).toString());
	System::out::println("d1.hash: " + Integer(d1->hashCode()).toString());
	System::out::println("d2.hash: " + Integer(d2->hashCode()).toString());

	Double* d3 = new Double(1.2);
	Object* d4 = new Double(1.2);
	ret = ret + !d1.get()->equals(1.2);
	ret = ret + !d1.get()->equals(d3);
	ret = ret + !d1.get()->equals(d1);
	ret = ret + !d1.get()->equals(d4);
	delete d3;
	delete d4;

	ret = ret + Assert::assertEquals(d1, d1);
	ret = ret + !Assert::assertEquals(d1, d2);

	return ret;
}

