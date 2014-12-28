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
	int test[] = { 1, 2, 3, 4};
	int n = sizeof(test) / sizeof(int);
	jt_handle_t *h = jt_create(n);

	print(test, n);
	while(jt_next_perm(h, test))
		print(test, n);

	jt_free(h);

	return 0;
}
