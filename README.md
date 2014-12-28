Johnson-Trotter-Permutations
============================

##Intro
C implementation of the Johnson–Trotter algorithm to generate permutations. The next permutation is created by swapping only 2 values. More info [here](http://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm) and [here](http://www.cut-the-knot.org/Curriculum/Combinatorics/JohnsonTrotter.shtml).

##How to use
####1. Create a handle
Create a handle by giving the number of elements in the array and the size of
an element.
```c
jt_handle_t *h = jt_create(number_of_elements, element_size);
```
####2. Generate permutations
Generate the permutations using `jt_next_perm()` which takes as the first parameter the handle and as the second 
parameter the array where to make the swap.

```c
do {
  //Do something with the permutation
} while(jt_next_perm(h, myArray));
```

####3. Free the handle
After you're done don't forget to free the memory using `jt_free()`.
```c
jt_free(h);
```

##Complete example
You can find a complete example in [main.c](https://github.com/dumrelu/Johnson-Trotter-Permutations/blob/master/src/main.c).

##Examples outputs
####3 element array permutations
123
132
231
321
312
213

####4 element array permutations
1234
1243
1342
2341
2431
1432
1423
1324
2314
2413
3412
3421
4321
4312
4213
3214
3124
4123
4132
4231
3241
3142
2143
2134
