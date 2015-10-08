/*
 * Object.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPPDK_LANG_OBJECT_H_
#define CPPDK_LANG_OBJECT_H_

class Object {
public:
	Object();
	virtual ~Object();

	int hashCode();
};

#endif /* CPPDK_LANG_OBJECT_H_ */
