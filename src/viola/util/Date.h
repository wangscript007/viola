/*
 * Date.h
 *
 *  Created on: 2015/10/28
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_UTIL_DATE_H_
#define SRC_VIOLA_UTIL_DATE_H_

#include "Object.h"
#include "System.h"

class Date: public Object {
private:
	long timestamp;
public:
	Date();
	Date(long timestamp);
	virtual ~Date();

	long getTime();
};

#endif /* SRC_VIOLA_UTIL_DATE_H_ */
