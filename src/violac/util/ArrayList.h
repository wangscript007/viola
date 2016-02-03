/*
 * ArrayList.h
 *
 *  Created on: 2016/02/03
 *      Author: tsubaki
 */

#ifndef SRC_VIOLAC_UTIL_ARRAYLIST_H_
#define SRC_VIOLAC_UTIL_ARRAYLIST_H_

#include <stdlib.h>

typedef struct {
	void* array;
	int size;
	int maxSize;
} ArrayList;

ArrayList* ArrayList_new();
void ArrayList_add(ArrayList* list, void* data);
void* ArrayList_get(ArrayList* list, int idx);
int ArrayList_size(ArrayList* list);
void ArrayList_free(ArrayList* list);

#endif /* SRC_VIOLAC_UTIL_ARRAYLIST_H_ */
