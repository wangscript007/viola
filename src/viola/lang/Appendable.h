/*
 * Appendable.h
 *
 *  Created on: 2015/10/23
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LANG_APPENDABLE_H_
#define SRC_VIOLA_LANG_APPENDABLE_H_

#include "Object.h"
#include "IOException.h"

class Appendable {
public:
	Appendable();
	virtual ~Appendable();

	virtual void append(std::string line) throw (IOException);
};

#endif /* SRC_VIOLA_LANG_APPENDABLE_H_ */
