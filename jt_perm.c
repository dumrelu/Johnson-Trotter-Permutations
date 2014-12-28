#include <stdio.h>
#include <stdlib.h>
#include "jt_perm.h"

#include <unistd.h>

#define LEFT -1

//Directed integer internal structure
typedef struct {
	int integer;		//Original index in the array
	int dir;			//LEFT or RIGHT
} directed_int;

//Handle structure
struct jt_handle {
	int n;				//Number of elements
	directed_int *elems;//n directed integers
};

//Malloc with error checking
void *emalloc(size_t size)
{
	void *p = malloc(size);

	if(!p) {
		fprintf(stderr, "Memory allocation failed(emalloc).\n");
		exit(-1);
	}

	return p;
}

//Allocates memory and initializes the handle
jt_handle_t *jt_create(int n)
{
	jt_handle_t *h = (jt_handle_t*) emalloc(sizeof(jt_handle_t));

	h->n = n;
	h->elems = (directed_int*) emalloc(sizeof(directed_int) * n);

	int i;
	for(i = 0; i < n; ++i) {
		h->elems[i].integer = i;
		h->elems[i].dir     = LEFT;
	}

	return h;
}

//Check if it's a mobile integer
int is_mobile_integer(jt_handle_t *h, int index)
{
	int neighbor = index + h->elems[index].dir;

	//If the neighbor index is not in range
	if(neighbor < 0 || neighbor >= h->n)
		return 0;

	return (h->elems[index].integer > h->elems[neighbor].integer);
}

//Finds the largest mobile integer
int largest_mobile_integer(jt_handle_t *h)
{
	int i, k = -1;

	for(i = 0; i < h->n; ++i)
		if(is_mobile_integer(h, i) && 
			( k == -1 || h->elems[i].integer > h->elems[k].integer))
			k = i;

	return k;
}

//Swap the values in the handle and in the array
void swap_values(jt_handle_t *h, jt_value_t *array, int i, int j)
{
	directed_int swap_di = h->elems[i];
	h->elems[i] = h->elems[j];
	h->elems[j] = swap_di;

	jt_value_t swap_v = array[h->elems[i].integer];
	array[h->elems[i].integer] = array[h->elems[j].integer];
	array[h->elems[j].integer] = swap_v;
}

int jt_next_perm(jt_handle_t *h, jt_value_t *array)
{
	int k = largest_mobile_integer(h);
	int neighbor = k + h->elems[k].dir;


	//If no mobile integers left
	if(k == -1)
		return 0;

	//Reverse direction for all integers > k's integer
	int i;
	for(i = 0; i < h->n; ++i)
		if(h->elems[i].integer > h->elems[k].integer)
			h->elems[i].dir *= -1;

	//Swap k with neighbor
	swap_values(h, array, k, neighbor);

	return 1;
}

void jt_free(jt_handle_t *h)
{
	free(h->elems);
	free(h);
}
