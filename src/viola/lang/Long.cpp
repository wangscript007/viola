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
bool Long::equals(std::shared_ptr<Object> obj) {
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
std::string Long::getClassName() {
	return "Long";
}

//Override
std::string Long::toString() {
	std::string str(getClassName());
	str.append("]");
	str.append(std::to_string(this->hashCode()));
	str.append("]");
	return str;
}
