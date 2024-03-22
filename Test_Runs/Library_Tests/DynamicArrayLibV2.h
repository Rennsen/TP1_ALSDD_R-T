// Dynamic Array Abstract Machine Library
#ifndef DYNAMIC_ARRAY_ABSTRMACH_H
#define DYNAMIC_ARRAY_ABSTRMACH_H

#include <stdlib.h>

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
void removeMultiplesARR(DynArrMachine *dam, int multiple);

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

#endif