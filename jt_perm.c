#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jt_perm.h"

#define LEFT -1

//Directed integer internal structure
typedef struct {
	int integer;		//Original index in the array
	int dir;		//-1 or 1
} directed_int;

//Handle structure
struct jt_handle {
	size_t n;		//Number of elements
	directed_int *elems;	//n directed integers
	size_t size;		//Size of an element in the array
	void *buffer;		//Zone of memory used to swap values
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
jt_handle_t *jt_create(size_t n, size_t size)
{
	jt_handle_t *h = (jt_handle_t*) emalloc(sizeof(jt_handle_t));

	h->n = n;
	h->size = size;
	h->elems = (directed_int*) emalloc(sizeof(directed_int) * n);
	h->buffer = emalloc(size);

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
void swap_values(jt_handle_t *h, void *array, int i, int j)
{
	directed_int swap_di = h->elems[i];
	h->elems[i] = h->elems[j];
	h->elems[j] = swap_di;

	memcpy(h->buffer, array + h->elems[i].integer * h->size, h->size);
	memcpy(array + h->elems[i].integer * h->size, 
	       array + h->elems[j].integer * h->size, h->size);
	memcpy(array + h->elems[j].integer * h->size, h->buffer, h->size);
}

int jt_next_perm(jt_handle_t *h, void *array)
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

	//Swap k with neighbor in h->elems and in array
	swap_values(h, array, k, neighbor);

	return 1;
}

void jt_free(jt_handle_t *h)
{
	free(h->elems);
	free(h->buffer);
	free(h);
}
