// Linked List Abstract Machine Library
#ifndef QST3LIB_H
#define QST3LIB_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "AbstractMachineSingly.h"

void ass_range_index(cell *p, int index); // New function to assign range index


void ass_range_index(cell *p, int index)
{
    if (p != NULL)
    {
        p->rangeIndex = index;
    }
}

// Linked List Implementation
typedef struct LinkedList
{
    cell *head;
    size_t size;
} LinkedList;

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void addToLinkedList(LinkedList *list, int element);
void removeMultiplesLL(LinkedList *list, int multiple);

// ... (implementation of LinkedList functions)
LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroyLinkedList(LinkedList *list)
{
    free_cell(list->head);
    free(list);
}

void addToLinkedList(LinkedList *list, int element)
{
    cell *newCell;
    allocate_cell(&newCell);
    ass_val(newCell, element);
    newCell->deleted = false;
    ass_adr(newCell, NULL);
    if (list->head == NULL)
    {
        list->head = newCell;
    }
    else
    {
        cell *current = list->head;
        while (next(current) != NULL)
        {
            current = next(current);
        }
        ass_adr(current, newCell);
    }
    list->size++;
}

void removeMultiplesLL(LinkedList *list, int multiple)
{
    cell *current = list->head;
    while (current != NULL)
    {
        if (!current->deleted && value(current) % multiple == 0 && value(current) != multiple)
        {
            current->deleted = true;
        }
        current = next(current);
    }
}

// Prime Generation
void generatePrimesLinkedList(LinkedList *primes, int n)
{
    addToLinkedList(primes, 2); // Add 2 to the linked list
    for (int i = 3; i <= n; i += 2)
    {
        addToLinkedList(primes, i);
    }

    cell *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = value(current);
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesLL(primes, currentPrime);
        current = next(current);
    }
}
// ... (implementation of generatePrimesLinkedList)

// Index by Range
void indexByRange(LinkedList *primes, int range)
{
    cell *current = primes->head;
    int index = 1;
    int rangeCount = 1;

    while (current != NULL)
    {
        if (!current->deleted)
        {
            ass_range_index(current, rangeCount);
            if (index % range == 0)
            {
                rangeCount++;
            }
            index++;
        }
        current = next(current);
    }
}

// Display by Range
void displayByRange(LinkedList *primes, int range)
{
    cell *current = primes->head;
    int currentRange = 1;

    while (current != NULL)
    {
        if (!current->deleted && current->rangeIndex == currentRange)
        {
            printf("%d|", value(current));
        }
        else if (!current->deleted && current->rangeIndex > currentRange)
        {
            printf("  ||  ");
            currentRange = current->rangeIndex;
            printf("|%d|", value(current));
        }
        current = next(current);
    }
    printf("\n");
}

#endif