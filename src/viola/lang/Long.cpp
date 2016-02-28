/*
 * Long.cpp
 *
 *  Created on: 2015/10/12
 *      Author: tsubaki
 */

#include <Long.h>

//Long::Long(long value) {
//	this->value = value;
//}

Long::Long(int64_t value) {
	this->value = value;
}

Long::~Long() {
	//noop
}

int64_t Long::get() {
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
uint32_t Long::hashCode() {
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
	return std::to_string(this->hashCode());
}
