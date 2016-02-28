/*
 * System.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#pragma once
#include <time.h>
#include <sys/time.h>
#include "Object.h"

class System: public Object {
public:
	System();
	~System();

	static uint64_t currentTimemillis() {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		uint64_t sec = tv.tv_sec;
		uint64_t usec = tv.tv_usec;
		return sec * 1000 + (usec / 1000);
	}

	static uint64_t currentTimeseconds() {
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

		static void println(uint32_t value) {
			printf("%d\n", value);
		}

		static void println(uint64_t value) {
			printf("%llu\n", value);
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
