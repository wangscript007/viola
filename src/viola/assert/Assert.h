/*
 * Assert.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef VIOLA_EXT_ASSERT_H_
#define VIOLA_EXT_ASSERT_H_

#include "viola.h"

class Assert {
public:
	Assert();
	virtual ~Assert();

	static int assertEquals(double expected, double actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(int expected, int actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(long expected, long actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(_Double expected, _Double actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(_Integer expected, _Integer actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(_Long expected, _Long actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(_Object expected, _Object actual) {
		if (expected.get()->equals(actual.get())) {
			return 0;
		}
		return 1;
	}

	static int assertEquals(_Strings expected, _Strings actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

};

#endif /* VIOLA_EXT_ASSERT_H_ */
