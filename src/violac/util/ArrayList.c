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
		return NULL;
	}
	list->size = 0;
	list->maxSize = 16;

	list->array = (void**) calloc(sizeof(void*), list->maxSize);
	if (!list->array) {
		free(list);
		return NULL;
	}

	return list;
}

void ArrayList_put(ArrayList* list, uint32_t idx, void* data) {
	list->array[idx] = data;
	if (list->size <= idx) {
		list->size = idx + 1;
	}
}

void ArrayList_add(ArrayList* list, void* data) {
	list->array[list->size] = data;
	list->size++;
}

void* ArrayList_get(ArrayList* list, uint32_t idx) {
	return list->array[idx];
}

uint32_t ArrayList_size(ArrayList* list) {
	return list->size;
}

uint32_t ArrayList_maxSize(ArrayList* list) {
	return list->maxSize;
}

void ArrayList_free(ArrayList* list) {
	free(list->array);
	free(list);
}
