/*
 * DoubleTest.cpp
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#include "Double.h"

typedef std::shared_ptr<Double> doublep;

int main() {
	int ret = 0;

	doublep d1 = std::make_shared<Double>(1.2);
	doublep d2 = std::make_shared<Double>(3.4);
	printf("obj1.className: <%s>\n", d1.get()->getClassName().c_str());

	printf("obj1.long: <%lu>, obj1.hashCode: <%d>\n",
			d1.get()->doubleToLongBits(), d1.get()->hashCode());
	printf("obj2.long: <%lu>, obj2.hashCode: <%d>\n",
			d2.get()->doubleToLongBits(), d2.get()->hashCode());

	return ret;
}

