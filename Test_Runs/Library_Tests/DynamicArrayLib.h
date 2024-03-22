#ifndef DYNAMIC_ARRAY_ABSTRMACH_H
#define DYNAMIC_ARRAY_ABSTRMACH_H

#include <stdlib.h>

typedef struct DynArrMachine
{
    int *arr;
    size_t size;
    size_t capacity;
} DynArrMachine;

void initDynArray(DynArrMachine **dam, size_t initialCapacity);
void freeDynArray(DynArrMachine *dam);
int getValue(DynArrMachine *dam, size_t index);
void setValue(DynArrMachine *dam, size_t index, int value);
void expandCapacity(DynArrMachine *dam);
void addElement(DynArrMachine *dam, int value);
void removeElement(DynArrMachine *dam, size_t index);

void initDynArray(DynArrMachine **dam, size_t initialCapacity)
{
    *dam = (DynArrMachine *)malloc(sizeof(DynArrMachine));
    (*dam)->arr = (int *)malloc(initialCapacity * sizeof(int));
    (*dam)->size = 0;
    (*dam)->capacity = initialCapacity;
}

void freeDynArray(DynArrMachine *dam)
{
    free(dam->arr);
    free(dam);
}

int getValue(DynArrMachine *dam, size_t index)
{
    if (index >= dam->size)
    {
        perror("Out of bounds.");
        return -1;
    }
    return dam->arr[index];
}

void setValue(DynArrMachine *dam, size_t index, int value)
{
    if (index >= dam->size)
    {
        perror("Out of bounds.");
        return;
    }
    dam->arr[index] = value;
}

void expandCapacity(DynArrMachine *dam)
{
    size_t newCapacity = dam->capacity * 2;
    dam->arr = (int *)realloc(dam->arr, newCapacity * sizeof(int));
    dam->capacity = newCapacity;
}

void addElement(DynArrMachine *dam, int value)
{
    if (dam->size == dam->capacity)
    {
        expandCapacity(dam);
    }
    dam->arr[dam->size] = value;
    dam->size++;
}

void removeElement(DynArrMachine *dam, size_t index)
{
    if (index >= dam->size)
    {
        perror("Out of bounds.");
        return;
    }
    for (size_t i = index; i < dam->size - 1; i++)
    {
        dam->arr[i] = dam->arr[i + 1];
    }
    dam->size--;
}

#endif