/*
 * Boolean.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LANG_BOOLEAN_H_
#define SRC_VIOLA_LANG_BOOLEAN_H_

#include "Object.h"

class Boolean: public Object {
private:
	bool value;
public:
	Boolean(bool tof);
	~Boolean();

	bool get();

	bool equals(Boolean* obj);
	bool equals(std::shared_ptr<Boolean> obj);
	bool equals(bool arg);

	//Override
	int hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();
};

#endif /* SRC_VIOLA_LANG_BOOLEAN_H_ */
