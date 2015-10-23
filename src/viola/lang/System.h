/*
 * System.h
 *
 *  Created on: 2015/10/24
 *      Author: tsubaki
 */

#ifndef SRC_VIOLA_LANG_SYSTEM_H_
#define SRC_VIOLA_LANG_SYSTEM_H_

#include "Object.h"

class System: public Object {
public:
	System();
	~System();

	class out {
	public:
		static void print(std::string line) {
			printf("%s", line.c_str());
		}

		static void println(std::string line) {
			printf("%s\n", line.c_str());
		}
	};
};

#endif /* SRC_VIOLA_LANG_SYSTEM_H_ */
