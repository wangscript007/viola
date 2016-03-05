/*
 * ArrayList.h
 *
 *  Created on: 2016/02/03
 *      Author: tsubaki
 */

#pragma once
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	void** array;
	uint32_t size;
	uint32_t maxSize;
} ArrayList;

ArrayList* ArrayList_new();

void ArrayList_add(ArrayList* list, void* data);

void ArrayList_put(ArrayList* list, uint32_t idx, void* data);

void* ArrayList_get(ArrayList* list, uint32_t idx);

uint32_t ArrayList_size(ArrayList* list);

uint32_t ArrayList_maxSize(ArrayList* list);

void ArrayList_free(ArrayList* list);

