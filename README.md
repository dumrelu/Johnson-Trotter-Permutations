Johnson-Trotter-Permutations
============================

##Intro
C implementation of the Johnson–Trotter algorithm to generate permutations. The next permutation is created by swapping only 2 values. More info [here](http://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm) and [here](http://www.cut-the-knot.org/Curriculum/Combinatorics/JohnsonTrotter.shtml).

##How to use
####1. Set the input array type
Go to [jt_perm.h](https://github.com/dumrelu/Johnson-Trotter-Permutations/blob/master/jt_perm.h) and change the
typedef of _jt_value_t_ to type you want.
```c
/*Examples*/
typedef int jt_value_t;        //Generate permutations for an array of ints
typedef double jt_value_t;     //Generate permutations for an array of doubles
typedef myType jt_value_t;     //Generate permutations for an array of myTypes
```

####2. Create a handle
Create a handle by giving the size of the array.
```c
jt_handle_t *h = jt_create(size_of_array);
```
####3. Generate permutations
Generate the permutations using `jt_next_perm()` which takes as the first parameter the handle and the second 
parameter an array of `jt_value_t`.

```c
do {
  //Do something with the permutation
} while(jt_next_perm(h, myArray));
```

####4. Free the handle
After you're done don't forget to free the memory using `jt_free()`
```c
jt_free(h);
```

##Complete example
You can find a complete example in [main.c](https://github.com/dumrelu/Johnson-Trotter-Permutations/blob/master/main.c).

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
