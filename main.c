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
	int myArray[] = { 1, 2, 3};
	int size_of_array = sizeof(myArray) / sizeof(myArray[0]);
	jt_handle_t *h = jt_create(size_of_array);

	do {
		print(myArray, size_of_array);
	} while(jt_next_perm(h, myArray));

	jt_free(h);

	return 0;
}
