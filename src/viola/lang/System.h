/*
 * System.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LANG_SYSTEM_H_
#define SRC_VIOLA_LANG_SYSTEM_H_

#include <time.h>
#include <sys/time.h>
#include "Object.h"

class System: public Object {
public:
	System();
	~System();

	static long currentTimemillis() {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		long sec = tv.tv_sec;
		long usec = tv.tv_usec;
		return sec * 1000 + (usec / 1000);
	}

	static long currentTimeseconds() {
		time_t now = time(NULL);
		return (long) now;
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
			if (line == NULL) {
				printf("NULL\n");
				return;
			}
			printf("%s\n", line->toString().c_str());
		}

		static void println(Object& line) {
			printf("%s\n", line.toString().c_str());
		}

		static void println(std::shared_ptr<Object> line) {
			if (line == NULL) {
				printf("NULL\n");
				return;
			}
			printf("%s\n", line->toString().c_str());
		}

	};
};

#endif /* SRC_VIOLA_LANG_SYSTEM_H_ */
