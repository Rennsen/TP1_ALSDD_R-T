// Dynamic Array Abstract Machine Library
#ifndef DYNAMIC_ARRAY_ABSTRMACH_H
#define DYNAMIC_ARRAY_ABSTRMACH_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct DynArrMachine
{
    int *arr;
    bool *deleted;
    size_t size;
    size_t capacity;
} DynArrMachine;

void initDynArray(DynArrMachine **dam, size_t initialCapacity);
void freeDynArray(DynArrMachine *dam);
int getValue(DynArrMachine *dam, size_t index);
void setValue(DynArrMachine *dam, size_t index, int value);
void expandCapacity(DynArrMachine *dam);
void addElement(DynArrMachine *dam, int value);
void printDynamicArray(DynArrMachine *array);
void removeMultiplesARR(DynArrMachine *dam, int multiple);
void generatePrimesDynamicArray(DynArrMachine *primes, int n);
void createInitialListDynamicArray(DynArrMachine *arr, int n);

#endif