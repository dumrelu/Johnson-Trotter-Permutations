/*
 * Implementation of the Johnson-Trotter algorithm to generate permutations.

 * Copyright (c) 2014 Dumitru Relu
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
