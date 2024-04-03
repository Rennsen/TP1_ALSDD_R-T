#include "DynamicArrayLib.h"

void initDynArray(DynArrMachine **dam, size_t initialCapacity)
{
    *dam = (DynArrMachine *)malloc(sizeof(DynArrMachine));
    (*dam)->arr = (int *)malloc(initialCapacity * sizeof(int));
    (*dam)->deleted = (bool *)malloc(initialCapacity * sizeof(bool));
    (*dam)->size = 0;
    (*dam)->capacity = initialCapacity;
}

void freeDynArray(DynArrMachine *dam)
{
    free(dam->arr);
    free(dam->deleted);
    free(dam);
}

int getValue(DynArrMachine *dam, size_t index)
{
    if (index >= dam->size)
    {
        return -1;
    }
    return dam->arr[index];
}

void setValue(DynArrMachine *dam, size_t index, int value)
{
    if (index >= dam->size)
    {
        return;
    }
    dam->arr[index] = value;
}

void expandCapacity(DynArrMachine *dam)
{
    size_t newCapacity = dam->capacity * 2;
    dam->arr = (int *)realloc(dam->arr, newCapacity * sizeof(int));
    dam->deleted = (bool *)realloc(dam->deleted, newCapacity * sizeof(bool));
    dam->capacity = newCapacity;
}

void addElement(DynArrMachine *dam, int value)
{
    if (dam->size == dam->capacity)
    {
        expandCapacity(dam);
    }
    dam->arr[dam->size] = value;
    dam->deleted[dam->size] = false;
    dam->size++;
}

void printDynamicArray(DynArrMachine *array)
{
    for (size_t i = 0; i < array->size; ++i)
    {
        if (!array->deleted[i])
        {
            printf("%d ", getValue(array, i));
        }
    }
}

void removeMultiplesARR(DynArrMachine *dam, int multiple)
{
    for (size_t i = 0; i < dam->size; ++i)
    {
        if (!dam->deleted[i] && dam->arr[i] % multiple == 0 && dam->arr[i] != multiple)
        {
            dam->deleted[i] = true;
        }
    }
}

// Prime Generation
void generatePrimesDynamicArray(DynArrMachine *primes, int n)
{
    addElement(primes, 2); // Add 2 to the dynamic array
    for (int i = 3; i <= n; i += 2)
    {
        addElement(primes, i);
    }

    for (size_t i = 0; i < primes->size; ++i)
    {
        int currentPrime = getValue(primes, i);
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesARR(primes, currentPrime);
    }
}

// Initial List Creation
void createInitialListDynamicArray(DynArrMachine *arr, int n)
{
    for (int i = 2; i <= n; i++)
    {
        addElement(arr, i);
    }
}