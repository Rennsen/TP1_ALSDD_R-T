#include "DynamicArrayLib.h"

// Initializes a dynamic array with the given initial capacity
void initDynArray(DynArrMachine **dam, size_t initialCapacity) {
    // Allocate memory for the DynArrMachine struct
    *dam = (DynArrMachine *)malloc(sizeof(DynArrMachine));

    // Allocate memory for the array and the deleted flags
    (*dam)->arr = (int *)malloc(initialCapacity * sizeof(int));
    (*dam)->deleted = (bool *)malloc(initialCapacity * sizeof(bool));

    // Initialize the size and capacity of the dynamic array
    (*dam)->size = 0;
    (*dam)->capacity = initialCapacity;
}

// Frees the memory used by the dynamic array
void freeDynArray(DynArrMachine *dam) {
    // Free the memory used by the array and the deleted flags
    free(dam->arr);
    free(dam->deleted);
    free(dam);
}

// Retrieves the value at the given index of the dynamic array
int getValue(DynArrMachine *dam, size_t index) {
    // Check if the index is within the bounds of the array
    if (index >= dam->size) {
        return -1; // Return -1 if the index is out of bounds
    }
    return dam->arr[index];
}

// Sets the value at the given index of the dynamic array
void setValue(DynArrMachine *dam, size_t index, int value) {
    // Check if the index is within the bounds of the array
    if (index >= dam->size) {
        return; // Do nothing if the index is out of bounds
    }
    dam->arr[index] = value;
}

// Expands the capacity of the dynamic array by doubling it
void expandCapacity(DynArrMachine *dam) {
    // Calculate the new capacity
    size_t newCapacity = dam->capacity * 2;

    // Reallocate memory for the array and the deleted flags
    dam->arr = (int *)realloc(dam->arr, newCapacity * sizeof(int));
    dam->deleted = (bool *)realloc(dam->deleted, newCapacity * sizeof(bool));

    // Update the capacity of the dynamic array
    dam->capacity = newCapacity;
}

// Adds an element to the dynamic array
void addElement(DynArrMachine *dam, int value) {
    // Check if the array needs to be expanded
    if (dam->size == dam->capacity) {
        expandCapacity(dam);
    }

    // Add the new element to the array and mark it as not deleted
    dam->arr[dam->size] = value;
    dam->deleted[dam->size] = false;
    dam->size++;
}

// Prints the non-deleted elements of the dynamic array
void printDynamicArray(DynArrMachine *array) {
    for (size_t i = 0; i < array->size; ++i) {
        if (!array->deleted[i]) {
            printf("| %d |", getValue(array, i));
        }
    }
}

// Removes all multiples of the given number (except the number itself) from the dynamic array
void removeMultiplesARR(DynArrMachine *dam, int multiple) {
    for (size_t i = 0; i < dam->size; ++i) {
        if (!dam->deleted[i] && dam->arr[i] % multiple == 0 && dam->arr[i] != multiple) {
            dam->deleted[i] = true;
        }
    }
}

// Generates a dynamic array of prime numbers up to the given limit
void generatePrimesDynamicArray(DynArrMachine *primes, int n) {
    addElement(primes, 2); // Add 2 to the dynamic array

    // Add all odd numbers from 3 to n
    for (int i = 3; i <= n; i += 2) {
        addElement(primes, i);
    }

    // Remove all multiples of each prime number from the array
    for (size_t i = 0; i < primes->size; ++i) {
        int currentPrime = getValue(primes, i);
        if (currentPrime * currentPrime > n) {
            break;
        }
        removeMultiplesARR(primes, currentPrime);
    }
}

// Creates a dynamic array of numbers from 2 to n
void createInitialListDynamicArray(DynArrMachine *arr, int n) {
    for (int i = 2; i <= n; i++) {
        addElement(arr, i);
    }
}