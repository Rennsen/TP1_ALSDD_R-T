---
# First Structure : Dynamic Arrays
---

# Dynamic Array Library Modules' Complexity Calculation (DynamicArrayLib)

## Overview

This part provides a detailed analysis of the time complexity of each module in the Dynamic Array Library (DynamicArrayLib). The library consists of various functions for dynamically managing arrays, including initialization, memory allocation, value retrieval, and manipulation.

## Modules

### initDynArray

This function initializes a dynamic array with a given initial capacity.

- Memory allocation for the DynArrMachine struct: O(1)
- Memory allocation for the 'arr' array: O(1)
- Memory allocation for the 'deleted' array: O(1)
- Total: O(1)

### freeDynArray

This function frees memory allocated for the dynamic array.

- Freeing the 'arr' array: O(1)
- Freeing the 'deleted' array: O(1)
- Freeing the DynArrMachine struct: O(1)
- Total: O(1)

### getValue

This function retrieves the value at a specified index in the dynamic array.

- Accessing the 'arr' array at a given index: O(1)
- Total: O(1)

### setValue

This function sets the value at a specified index in the dynamic array.

- Setting the value in the 'arr' array at a given index: O(1)
- Total: O(1)

### expandCapacity

This function expands the capacity of the dynamic array.

- Memory reallocation for the 'arr' array: O(n), where n is the new capacity
- Memory reallocation for the 'deleted' array: O(n), where n is the new capacity
- Total: O(n)

### addElement

This function adds an element to the dynamic array.

- Checking if resizing is necessary: O(1)
- If resizing is required, calling expandCapacity: O(n)
- Setting the value in the 'arr' array: O(1)
- Total: Amortized O(1) on average, O(n) in the worst case

### printDynamicArray

This function prints the elements of the dynamic array.

- Looping through each element in the 'arr' array: O(n)
- Total: O(n)

### removeMultiplesARR

This function removes multiples of a given number from the dynamic array.

- Looping through each element in the 'arr' array: O(n)
- Total: O(n)

### generatePrimesDynamicArray

This function generates prime numbers up to a specified value.

- Adding 2 to the dynamic array: O(1)
- Adding odd numbers to the dynamic array: O(n/2) = O(n) (since we're considering every odd number)
- Calling `removeMultiplesARR` for each element in the dynamic array (inside the loop): O(n) * O(n) = O(n^2)
- Total: O(n^2)

### createInitialListDynamicArray

This function creates an initial list in the dynamic array.

- Adding elements to the dynamic array: O(n)
- Total: O(n)

## Conclusion

The Dynamic Array Library modules exhibit various time complexities ranging from O(1) to O(n^2) depending on the specific operations performed.

---

# Global Analysis (Main Program "QST2_DynamicArray.c")

## Overview

This part provides a detailed analysis of the time complexity of the main program that represents the implementation of the Sieve of Eratosthenes algorithm with the dynamic array structure "QST2_DynamicArray.c".

1. **User Input:**
   - Declaring integer variable `n`: \( O(1) \)
   - Printing prompt message: \( O(1) \)
   - Reading input from the user: \( O(1) \)

2. **Initializing Initial List:**
   - Initializing pointer variable `initialList`: \( O(1) \)
   - Initializing the initial list: [\ O(1) + O(n) \] = \( O(n) \)

3. **Printing Initial List:**
   - Printing the initial list: \( O(n) \)

4. **Generating Primes:**
   - Initializing pointer variable `dynamicPrimes`: \( O(1) \)
   - Generating primes: \( O(n^2) \)
   - Printing the generated primes: \( O(n) \)

5. **Freeing Memory:**
   - Freeing memory allocated for `dynamicPrimes`: \( O(1) \)

Now, let's compute the final sum of complexities:

\[ O(1) + O(1) + O(1) + O(1) + O(1) + O(n) + O(n) + O(n^2) + O(n) + O(1) \]

Combining like terms:

\[ O(5 + 3n + n^2) \]

Simplify further:

\[ O(n^2) \]

## Final Time Complexity

The final time complexity of the program is \( O(n^2) \).

---

