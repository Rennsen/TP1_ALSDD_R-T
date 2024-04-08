initDynArray(DynArrMachine **dam, size_t initialCapacity):

    This function initializes a dynamic array by allocating memory for the DynArrMachine struct, the array, and the deleted flags.
    Time complexity: O(1), as the memory allocation operations are constant-time.


freeDynArray(DynArrMachine *dam):

    This function frees the memory used by the dynamic array.
    Time complexity: O(1), as the free() operations are constant-time, this accrording to the function free which is on c 


getValue(DynArrMachine *dam, size_t index):

    This function retrieves the value at the given index of the dynamic array.
    Time complexity: O(1), as the array access is a constant-time operation.

setValue(DynArrMachine *dam, size_t index, int value):

    This function sets the value at the given index of the dynamic array.
    Time complexity: O(1), as the array access is a constant-time operation.

expandCapacity(DynArrMachine *dam):

    This function expands the capacity of the dynamic array by doubling it.
    Time complexity: O(n), where n is the current capacity of the array, as the realloc() operation is proportional to the size of the allocated memory.

addElement(DynArrMachine *dam, int value):

    This function adds an element to the dynamic array.
    Time complexity: O(1) in the average case, as the array access and capacity expansion (if needed) are constant-time operations. In the worst case, when the capacity needs to be expanded, the time complexity is O(n), where n is the current capacity of the array.

printDynamicArray(DynArrMachine *array):

    This function prints the non-deleted elements of the dynamic array.
    Time complexity: O(n), where n is the size of the dynamic array, as the function iterates through all the elements.

removeMultiplesARR(DynArrMachine *dam, int multiple):

  
    The function iterates through the entire dynamic array of size dam->size.
    For each element in the array, the function performs the following operations:
        Check if the element is not already deleted (!dam->deleted[i])
        Check if the element is a multiple of the given multiple (dam->arr[i] % multiple == 0)
        Check if the element is not equal to the multiple itself (dam->arr[i] != multiple)
    If all these conditions are met, the function marks the element as deleted (dam->deleted[i] = true).

The time complexity of this function is O(n), where n is the size of the dynamic array (dam->size), because the function needs to iterate through all the elements in the array.

To explain this in more detail:

    The outer loop iterates through the entire dynamic array of size n, which takes O(n) time.
    Inside the loop, the function performs a constant number of operations (3 checks and 1 assignment) for each element.
    The time complexity of these constant-time operations is O(1).
    Therefore, the overall time complexity of the removeMultiplesARR function is O(n * 1) = O(n).

generatePrimesDynamicArray(DynArrMachine *primes, int n):

  
    Adding 2 to the dynamic array: O(1)
    Adding all odd numbers from 3 to n: O(n/2) = O(n)
    Removing all multiples of each prime number from the array:
        The outer loop iterates through the primes->size elements, which is let's say k (the number of prime numbers up to n).
        For each prime number currentPrime, the function calls removeMultiplesARR(primes, currentPrime).
        The removeMultiplesARR function has a time complexity of O(n), where n is the size of the primes dynamic array.
        Therefore, the total time complexity of this step is O(k * n), where k is the number of prime numbers up to n.

Now, let's analyze the total time complexity:

Total time complexity = O(1) + O(n) + O(k * n)

To determine the value of k, we can use the Prime Number Theorem again, which states that the number of prime numbers up to n is approximately n / ln(n).

Substituting this into the total time complexity expression, we get:

Total time complexity = O(1) + O(n) + O((n / ln(n)) * n)
= O(1) + O(n) + O(n^2 / ln(n))
= O(n^2 / ln(n))

Since ln(n) grows more slowly than any power of n, we can simplify the time complexity to:

Total time complexity = O(n^2)

createInitialListDynamicArray(DynArrMachine *arr, int n):

    This function creates a dynamic array of numbers from 2 to n.
    Time complexity: O(n), as the function iterates through the range from 2 to n and adds each number to the dynamic array.

In summary, the time complexities of the functions are:

    initDynArray: O(1)
    freeDynArray: O(1)
    getValue: O(1)
    setValue: O(1)
    expandCapacity: O(n)
    addElement: O(1) on average, O(n) in the worst case
    printDynamicArray: O(n)
    removeMultiplesARR: O(n)
    generatePrimesDynamicArray: O(n^2)
    createInitialListDynamicArray: O(n)

    for the main program


    for the linked list we have :

    allocate_cell_2(cell_2 **p):
        This function allocates memory for a cell_2 struct.
        Time Complexity: O(1), as the malloc() operation is a constant-time operation.
    free_cell_2(cell_2 *head):
        This function frees the memory used by a linked list of cell_2 structs.
        Time Complexity: O(n), where n is the number of cells in the linked list, as the function iterates through the entire list and calls free() on each cell, and it will be o(1) if we free the head only 
    value_2(cell_2 *p), next_2(cell_2 *p), ass_val_2(cell_2 *p, int v), ass_adr_2(cell_2 *p, cell_2 *q), deleted_2(cell_2 *p), ass_deleted_2(cell_2 *p, bool value):
        These functions perform constant-time operations on the cell_2 struct.
        Time Complexity: O(1) for each function.
    createLinkedList_2():
        This function creates a new LinkedList_2 struct.
        Time Complexity: O(1), as the memory allocation and initialization operations are constant-time.
    destroyLinkedList_2(LinkedList_2 *list):
        This function destroys a LinkedList_2 struct.
        Time Complexity: O(n), where n is the number of cells in the linked list, as it calls free_cell_2() on the linked list.
    addToLinkedList_2(LinkedList_2 *list, int element):
        This function adds an element to the linked list.
        Time Complexity: O(n), where n is the number of cells in the linked list, as the function needs to traverse and iterate through the list to find the end.
    removeMultiplesLL_2(LinkedList_2 *list, int multiple):
        This function removes all multiples of a given number (except the number itself) from the linked list.
        Time Complexity: O(n), where n is the number of cells in the linked list, as the function needs to iterate through the entire list.
    generatePrimesLinkedList_2(LinkedList_2 *primes, int n):
        This function generates a linked list of prime numbers up to the given limit.
        Time Complexity: O(n log log n), which is the time complexity of the Sieve of Eratosthenes algorithm used to generate prime numbers.
        To prove this, let's go through the steps of the algorithm: a. The first step is to add 2 to the linked list, which takes O(1) time. b. The next step is to add all odd numbers from 3 to n to the linked list. This takes O(n/2) = O(n) time. c. The final step is to remove all multiples of each prime number from the list. This step is the same as the Sieve of Eratosthenes algorithm, which has a time complexity of O(n log log n). Therefore, the overall time complexity of generatePrimesLinkedList_2 is O(n log log n).
        
        
        createInitialListLinkedList_2(LinkedList_2 *list, int n):
        This function creates a linked list of numbers from 2 to n.
        Time Complexity: O(n), as the function iterates through the range from 2 to n and adds each number to the linked list.
    printListLogic_2(cell_2 *head):
        This function prints the non-deleted elements of a linked list.
        Time Complexity: O(n), where n is the number of non-deleted cells in the linked list, as the function needs to iterate through the entire list.
    printList_2(cell_2 *head):
        This function prints all the elements of a linked list.
        Time Complexity: O(n), where n is the number of cells in the linked list, as the function needs to iterate through the entire list.

In summary, the time complexities of the functions are:

    allocate_cell_2: O(1)
    free_cell_2: O(n)
    value_2, next_2, ass_val_2, ass_adr_2, deleted_2, ass_deleted_2: O(1)
    createLinkedList_2: O(1)
    destroyLinkedList_2: O(n)
    addToLinkedList_2: O(n)
    removeMultiplesLL_2: O(n)
    generatePrimesLinkedList_2: O(n log log n)
    createInitialListLinkedList_2: O(n)
    printListLogic_2: O(n)
    printList_2: O(n)

The most critical functions in terms of time complexity are generatePrimesLinkedList_2 (O(n log log n)) and addToLinkedList_2, removeMultiplesLL_2, createInitialListLinkedList_2, printListLogic_2, and printList_2 (all O(n)).




finally as a comparaison between the both structures we have :

Memory Allocation:

Linked List: Allocates memory for each element individually, leading to more flexible memory management as each element can be of a different size. However, it incurs overhead due to the need for pointers and additional memory allocations.
Dynamic Array: Allocates a contiguous block of memory for the array, making it more memory-efficient in terms of storage and access times. However, resizing the array can be costly as it requires reallocating and copying elements to a new location.
Access Time:

Linked List: Accessing elements by index in a linked list requires traversing the list from the head, which can be slower for large lists.
Dynamic Array: Accessing elements by index in a dynamic array is O(1) time complexity, as the elements are stored contiguously in memory.
Insertion and Deletion:

Linked List: Insertions and deletions at the beginning or middle of the list are more efficient, as they only require adjusting pointers. However, accessing elements by index requires traversal, making it less efficient.
Dynamic Array: Insertions and deletions at the end of the array are more efficient, especially if there is sufficient capacity. Insertions or deletions in the middle of the array require shifting elements, which can be costly.
Memory Overhead:

Linked List: Requires additional memory for pointers, which can increase memory overhead.
Dynamic Array: Requires memory for the array and possibly additional memory for resizing, but does not have the overhead of pointers for each element.
Usage:

Linked List: Suitable for scenarios where frequent insertions and deletions at arbitrary positions are required, or when the size of the list is not known in advance.
Dynamic Array: Suitable for scenarios where fast access to elements by index is required, or when the size of the collection is expected to remain relatively stable.