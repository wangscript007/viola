/*
 * System.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LANG_SYSTEM_H_
#define SRC_VIOLA_LANG_SYSTEM_H_

#include <time.h>
#include "Object.h"

class System: public Object {
public:
	System();
	~System();

	static long currentTimemillis() {
		time_t now = time(NULL);
		return (long) (((double) now) * 1000);
	}

	class out {
	public:

		static void println() {
			printf("\n");
		}

		static void println(int value) {
			printf("%d\n", value);
		}

		static void println(long value) {
			printf("%ld\n", value);
		}

		static void println(bool tof) {
			printf("%d\n", tof);
		}

		static void println(std::string line) {
			printf("%s\n", line.c_str());
		}

		static void println(Object* line) {
			printf("%s\n", line->toString().c_str());
		}

		static void println(std::shared_ptr<Object> line) {
			printf("%s\n", line->toString().c_str());
		}
	};
};

#endif /* SRC_VIOLA_LANG_SYSTEM_H_ */
