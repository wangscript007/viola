/*
 * Assert.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#pragma once
#include "Double.h"
#include "Integer.h"
#include "Long.h"
#include "Object.h"
#include "Strings.h"

typedef std::shared_ptr<Double> _Double;
typedef std::shared_ptr<Integer> _Integer;
typedef std::shared_ptr<Long> _Long;
typedef std::shared_ptr<Object> _Object;
typedef std::shared_ptr<Strings> _Strings;

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
