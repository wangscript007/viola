#include "violac.h"
#include <stdint.h>

int main() {
	ArrayList* list = ArrayList_new();
	printf("list: %d\n", list);
	printf("maxSize: %d\n", ArrayList_maxSize(list));
	ArrayList_add(list, "foobar");
	printf("get: %s\n", ArrayList_get(list, 0));
	ArrayList_free(list);

	return 0;
}
