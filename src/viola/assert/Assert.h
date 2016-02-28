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

	static uint32_t assertEquals(double expected, double actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(int32_t expected, int32_t actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(long expected, long actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(int64_t expected, int64_t actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(_Double expected, _Double actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

	static uint16_t assertEquals(_Integer expected, _Integer actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(_Long expected, _Long actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(_Object expected, _Object actual) {
		if (expected.get()->equals(actual.get())) {
			return 0;
		}
		return 1;
	}

	static uint32_t assertEquals(_Strings expected, _Strings actual) {
		if (expected->equals(actual)) {
			return 0;
		}
		return 1;
	}

};
