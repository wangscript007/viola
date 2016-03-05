/*
 * Process.h
 *
 *  Created on: 2016/03/03
 *      Author: tsubaki
 */

#pragma once
#include "Object.h"

class Process: public Object {
public:
	Process();
	virtual ~Process();

	int fork();
};
