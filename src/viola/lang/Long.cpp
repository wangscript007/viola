/*
 * Long.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include <Long.h>

Long::Long(long value) {
	this->value = value;
}

Long::~Long() {
	//noop
}

long Long::get() {
	return value;
}

bool Long::equals(Long* obj) {
	return this->equals(obj->get());
}
bool Long::equals(object obj) {
	return this->equals((Long*) obj.get());

}
bool Long::equals(long arg) {
	if (get() == arg) {
		return true;
	}

	return false;
}

//Override
int Long::hashCode() {
	return this->value;
}

//Override
bool Long::equals(Object* obj) {
	return this->equals((Long*) obj);
}

//Override
string Long::getClassName() {
	return "Long";
}

//Override
string Long::toString() {
	string str(getClassName());
	str.append("]");
	str.append(std::to_string(this->hashCode()));
	str.append("]");
	return str;
}
