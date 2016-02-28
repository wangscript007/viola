#include "violac.h"
#include <stdint.h>

int main() {
	ArrayList* list = ArrayList_new();
	printf("size: %d\n", ArrayList_size(list));
	ArrayList_free(list);

	return 0;
}
