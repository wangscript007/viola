/*
 * Assert.h
 *
 *  Created on: 2015/10/09
 *      Author: tsubaki
 */

#ifndef CPP_EXT_ASSERT_H_
#define CPP_EXT_ASSERT_H_

class Assert {
public:
	Assert();
	virtual ~Assert();

	static int assertEquals(int expected, int actual) {
		if (expected == actual) {
			return 0;
		}
		return 1;
	}

};

#endif /* CPP_EXT_ASSERT_H_ */
