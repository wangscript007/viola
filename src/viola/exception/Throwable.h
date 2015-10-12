/*
 * Throwable.h
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#ifndef VIOLA_LANG_THROWABLE_H_
#define VIOLA_LANG_THROWABLE_H_

#include "Object.h"

using namespace std;
typedef std::shared_ptr<Object> object;

class Throwable: public Object {
public:
	Throwable();
	~Throwable();
};

#endif /* VIOLA_LANG_THROWABLE_H_ */
