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
	printf("obj1.className: <%s>\n", d1.get()->getClassName().c_str());

	printf("obj1.long: <%lu>, obj1.hashCode: <%d>\n",
			d1.get()->doubleToLongBits(), d1.get()->hashCode());
	printf("obj2.long: <%lu>, obj2.hashCode: <%d>\n",
			d2.get()->doubleToLongBits(), d2.get()->hashCode());

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

