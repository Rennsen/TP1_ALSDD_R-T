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
- Calling `removeMultiplesARR` for each element in the dynamic array (inside the loop):
      The outer loop iterates through the primes->size elements, which is let's say k (the number of prime numbers up to n).
      For each prime number currentPrime, the function calls removeMultiplesARR(primes, currentPrime).
      The removeMultiplesARR function has a time complexity of O(n), where n is the size of the primes dynamic array.
      Therefore, the total time complexity of this step is O(k * n), where k is the number of prime numbers up to n.
      So, the total time complexity = O(1) + O(n) + O(k * n).
      To determine the value of k, we can use the Prime Number Theorem again, which states that the number of prime numbers up to n is approximately n / ln(n).
      Substituting this into the total time complexity expression, we get:
      Total time complexity = O(1) + O(n) + O((n / ln(n)) * n) = O(1) + O(n) + O(n^2 / ln(n)) = O(n^2 / ln(n)).
      Since ln(n) grows more slowly than any power of n, we can simplify the time complexity to:
      Total time complexity = O(n^2)
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
   - Initializing the initial list: [ O(1) + O(n) \] = \( O(n) \)

3. **Printing Initial List:**
   - Printing the initial list: \( O(n) \)

4. **Generating Primes:**
   - Initializing pointer variable `dynamicPrimes`: \( O(1) \)
   - Generating primes: \( O(n^2) \)
   - Printing the generated primes: \( O(n) \)

5. **Freeing Memory:**
   - Freeing memory allocated for `initialList`(initial list of integers): \( O(1) \) 
   - Freeing memory allocated for `dynamicPrimes`: \( O(1) \)

Now, let's compute the final sum of complexities:

\[ O(1) + O(1) + O(1) + O(1) + O(1) + O(n) + O(1) + O(n) + O(n^2) + O(n) + O(1) + O(1) \]

Combining like terms:

\[ O(8 + 3n + n^2) \]

Simplify further:

\[ O(n^2) \]  **Note: This is an approximate time complexity expression since many other O(1) instructions have been ignored and other more complex expressions simplified.**
              **Please refer to the computation of the complexity of each respective module in the part above**

## Final Time Complexity

The final time complexity of the program is \( O(n^2) \).

---
---
# Second Structure : Linked Lists
---

# LinkedList Library Modules' Complexity Calculation (LinkedListLib)

## Overview

This part provides a detailed analysis of the time complexity of each module in the Linked List Library (LinkedListLib).

## Abstract Machine Implementation

1. **allocate_cell:**
   - Memory allocation for a cell: O(1)

2. **free_cell:**
   - Freeing memory for each cell: O(n), where n is the number of cells in the list

3. **value:**
   - Accessing the value of a cell: O(1)

4. **next:**
   - Accessing the next pointer of a cell: O(1)

5. **ass_val:**
   - Assigning a value to a cell: O(1)

6. **ass_adr:**
   - Assigning an address (next pointer) to a cell: O(1)

## Linked List Implementation

1. **createLinkedList:**
   - Memory allocation for the LinkedList struct: O(1)

2. **destroyLinkedList:**
   - Freeing memory for all cells: O(n)

3. **addToLinkedList:**
   - Memory allocation for a new cell: O(1)
   - Traversing the list to find the last cell: O(n)
   - Assigning the new cell to the last cell's next pointer: O(1)

4. **removeMultiplesLL:**
   - Looping through each cell in the list: O(n)
   - Checking and potentially marking a cell as deleted: O(1)

5. **generatePrimesLinkedList:**
   - Adding 2 to the linked list: O(1)
   - Adding odd numbers to the linked list: O(n/2) = O(n)
   - Looping through each cell in the list: O(n)
   - Calling removeMultiplesLL for each prime number in the list:
      The outer loop iterates through the primes->size elements, which is let's say k (the number of prime numbers up to n).
      For each prime number currentPrime, the function calls removeMultiplesLL(primes, currentPrime).
      The removeMultiplesLL function has a time complexity of O(n), where n is the size of the primes dynamic array.
      Therefore, the total time complexity of this step is O(k * n), where k is the number of prime numbers up to n.
      So, the total time complexity = O(1) + O(n) + O(k * n).
      To determine the value of k, we can use the Prime Number Theorem again, which states that the number of prime numbers up to n is approximately n / ln(n).
      Substituting this into the total time complexity expression, we get:
      Total time complexity = O(1) + O(n) + O((n / ln(n)) * n) = O(1) + O(n) + O(n^2 / ln(n)) = O(n^2 / ln(n)).
      Since ln(n) grows more slowly than any power of n, we can simplify the time complexity to:
      Total time complexity = O(n^2)
   - Total: O(n^2)

6. **createInitialListLinkedList:**
   - Adding elements to the linked list: O(n)

7. **printListLogic:**
   - Looping through each cell in the list: O(n)
   - Printing the value of each non-deleted cell: O(1) per non-deleted cell

8. **printList:**
   - Looping through each cell in the list: O(n)
   - Printing the value of each cell: O(1) per cell

## Final Time Complexity

The Linked List Library modules exhibit various time complexities ranging from O(1) to O(n^2) depending on the specific operations performed.

---

# Global Analysis (Main Program "QST2_LinkedList.c")

## Overview

This part provides a detailed analysis of the time complexity of the main program that represents the implementation of the Sieve of Eratosthenes algorithm with the linked list structure "QST2_LinkedList.c".

1. **User Input:**
   - Declaring integer variable `n`: O(1)
   - Printing prompt message: O(1)
   - Reading input from the user: O(1)
   - Total: O(1)

2. **Creating Initial List:**
   - Creating a new linked list: O(1)
   - Adding elements to the linked list: O(n)
   - Printing the initial list: O(n)

3. **Generating Primes:**
   - Creating a new linked list for primes: O(1)
   - Generating primes: O(n^2)
   - Printing the generated primes: O(n)

4. **Freeing Memory:**
   - Freeing memory allocated for the initial list of integers: O(n)
   - Freeing memory allocated for the linked list of primes: O(n)
   
Now, let's compute the final sum of complexities:

\[ O(1) + O(1) + O(1) + O(1) + O(n) + O(n) + O(1) + O(n^2) + O(n) + O(n) + O(n) \]

Combining like terms:

\[ O(5 + 5n + n^2) \]

Simplify further:

\[ O(n^2) \]  **Note: This is an approximate time complexity expression since many other O(1) instructions have been ignored and other more complex expressions simplified.**
              **Please refer to the computation of the complexity of each respective module in the part above**

## Final Time Complexity

The final time complexity of the program is \( O(n^2) \).

---
---
# Final Comparison Between The Two Structures

## Dynamic Array vs. Linked List

In this context :

1. **Time Complexity:**
   - Both dynamic array and linked list implementations have a time complexity of O(n^2) for generating primes. This is because the generation process involves adding and removing elements, resulting in nested loops over the elements.

2. **Memory Management:**
   - The dynamic array implementation may suffer from the overhead of resizing when generating primes, potentially impacting performance due to frequent memory reallocation and copying.
   - The linked list implementation avoids the need for resizing, as elements can be inserted or deleted without the need for contiguous memory allocation. However, traversal overhead may still be present.

3. **Logical Deletion:**
   - The use of logical deletion in the dynamic array implementation (and also in the liked list implementation) mitigates some of the potential inefficiencies associated with physical deletion. By marking elements as deleted rather than physically removing them, the time complexity remains comparable to the linked list implementation for generating primes.

4. **Efficiency Considerations:**
   - Both implementations exhibit similar time complexity for generating primes, but their performance may differ depending on the specific operations and memory management requirements.
   - If memory management overhead is a concern, the linked list implementation may offer better efficiency due to its ability to handle insertions and deletions without resizing.
   - If random access or efficient searching is required, the dynamic array implementation may be more efficient due to its ability to directly access elements by index.

5. **Conclusion:**
   - In the context of the provided implementation, both dynamic arrays and linked lists exhibit similar time complexity for generating primes, thanks to the use of logical deletion in the dynamic array implementation. The choice between the two structures may depend on factors such as memory management overhead and specific requirements of the application.

---