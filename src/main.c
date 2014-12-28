#include <stdio.h>
#include <stdlib.h>
#include "jt_perm.h"

void print(int *test, int n)
{
	int i;
	for(i = 0; i < n; ++i)
		printf("%d", test[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	int myArray[]       = { 1, 2, 3 };
	size_t n_elems      = sizeof(myArray) / sizeof(int);
	size_t size_of_elem = sizeof(int);

	jt_handle_t *h = jt_create(n_elems, size_of_elem);

	do {
		print(myArray, n_elems);
	} while(jt_next_perm(h, myArray));

	jt_free(h);

	return 0;
}
