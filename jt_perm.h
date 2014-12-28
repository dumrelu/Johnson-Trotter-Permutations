/*
 * Implementation of the Johnson-Trotter algorithm
 *to generate permutations.
 */

#ifndef JT_PERM_H
#define JT_PERM_H

/* Handle used to save the current state of the algorithm. */
typedef struct jt_handle jt_handle_t;

/* Input type for the array of permutations. */
typedef int jt_value_t;

/* 
 * Create the handle used to generate the permutation for an
 *array of *n* elements.
 */
jt_handle_t *jt_create(
	int n
);

/*
 * Make the next permutation in *array* by swapping only 2 values.
 * Returns 1 if a permutation was made.
 * Returns 0 if no permutation was made(i.e. the last permutation was 
 *reached last call).
 */
int jt_next_perm(
	jt_handle_t *h, 
	jt_value_t *array
);

/*
 * Frees the memory used by the handle.
 */
void jt_free(
	jt_handle_t *h
);

#endif /*JT_PERM_H*/
