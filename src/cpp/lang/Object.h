/*
 * Object.h
 *
 *  Created on: 2015/10/08
 *      Author: tsubaki
 */

#ifndef CPP_LANG_OBJECT_H_
#define CPP_LANG_OBJECT_H_

#include <stdarg.h>

class Object {
private:
	int refCount = 1;
public:
	Object();
	virtual ~Object();

	Object* incrementReference();
	bool decrementReference();
	int getReference();

	static void tryDelete(Object* obj) {
		if (obj->decrementReference()) {
			delete obj;
		}
	}

	static void tryDelete(int argc, ...) {
		va_list args;
		va_start(args, argc);

		for (int i = 0; i < argc; i++) {
			Object* obj = va_arg(args, Object*);
			Object::tryDelete(obj);
		}
		va_end(args);
	}

	int hashCode();
};

#endif /* CPP_LANG_OBJECT_H_ */
