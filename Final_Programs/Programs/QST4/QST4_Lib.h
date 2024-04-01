// Linked List Abstract Machine Library
#ifndef QST4LIB_H
#define QST4LIB_H

#include <stdlib.h>
#include <stdio.h>
#include "AbstractMachineSingly.h"


// Linked List Implementation
struct LinkedList
{
    cell *head;
    size_t size;
};

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

void createInitialListLinkedList(LinkedList *list, int n)
{
    for (int i = 2; i <= n; i++)
    {
        addToLinkedList(list, i);
    }
}

// Function to create a sublist
LinkedList *createSublist()
{
    return createLinkedList();
}

// Function to add an element to a sublist
void addSublistElement(LinkedList *sublist, int value)
{
    addToLinkedList(sublist, value);
}

// Function to destroy a sublist
void destroySublist(LinkedList *sublist)
{
    destroyLinkedList(sublist);
}

// Prime Factorization
void factorizeNumber(int number, LinkedList *primeList, LinkedList *initialList)
{
    LinkedList *primeFactorsList = createLinkedList();
    int num = number;

    cell *currentPrime = primeList->head;
    while (currentPrime != NULL && num > 1)
    {
        int prime = value(currentPrime);
        while (num % prime == 0)
        {
            addToLinkedList(primeFactorsList, prime);
            num /= prime;
        }
        currentPrime = next(currentPrime);
    }

    cell *initialListCell = initialList->head;
    while (initialListCell != NULL)
    {
        if (value(initialListCell) == number)
        {
            initialListCell->sublist = primeFactorsList; // Assign sublist to the cell
            break;
        }
        initialListCell = next(initialListCell);
    }
}

void printFactorisation(cell * head){
     cell *current = head;
    while (current != NULL)
    {
        printf("%d: ", value(current));
        LinkedList *sublist = current->sublist;
        cell *sublist_current = sublist->head;
        while (sublist_current != NULL)
        {
            int count = 0;
            int prime = value(sublist_current);
            while (sublist_current != NULL && value(sublist_current) == prime)
            {
                count++;
                sublist_current = next(sublist_current);
            }
            printf("%d", prime);
            if (count > 1)
            {
                printf("^(%d)", count);
            }
            if (sublist_current != NULL)
            {
                printf(" * ");
            }
        }
        printf("\n");
        current = next(current);
    }
}


#endif