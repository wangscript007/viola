#include "violac.h"

int main() {
	ArrayList* list = ArrayList_new();
	printf("size: %d\n", list->size);
	printf("maxSize: %d\n", list->maxSize);
	ArrayList_free(list);
	return 0;
}
