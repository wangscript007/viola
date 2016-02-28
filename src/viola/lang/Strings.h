/*
 * String.h
 *
 *  Created on: 2015/10/07
 *      Author: tsubaki
 */

#pragma once
#include <string>
#include "Object.h"
#include "Integer.h"

class Strings: public Object {

private:
	std::string internal;

public:
	Strings();
	Strings(std::string str);
	~Strings();

	void append(std::string str);
	bool contains(std::string str);
	std::string replace(std::string target, std::string replacement);

	bool startWith(std::string prefix);
	bool endWith(std::string suffix);

	static std::string valueOf(long value);

	int length();
	bool isEmpty();

	bool equalsIgnoreCase(std::string str);

	bool equals(Strings* str);
	bool equals(std::shared_ptr<Object> obj);
	bool equals(std::string str);

	std::string operator+(std::shared_ptr<Object> o) {
		return this->internal + o->toString();
	}

	//Override
	uint32_t hashCode();
	bool equals(Object* obj);
	std::string getClassName();
	std::string toString();

};
