/*
 * ArrayList.c
 *
 *  Created on: 2016/02/03
 *      Author: tsubaki
 */

#include "ArrayList.h"

ArrayList* ArrayList_new() {
	ArrayList* list;
	list = (ArrayList*) calloc(1, sizeof(ArrayList));
	if (!list) {
		return 0;
	}
	list->size = 0;
	list->maxSize = 16;

	return list;
}

void ArrayList_add(ArrayList* list, void* data) {

}

void* ArrayList_get(ArrayList* list, uint32_t idx) {
	return 0;
}

uint32_t ArrayList_size(ArrayList* list) {
	return list->size;
}

void ArrayList_free(ArrayList* list) {
	free(list);
}
