#ifndef QST5LIB_H
#define QST5LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LinkedList_5 LinkedList_5;
typedef struct cell_5
{
    int value_5;
    bool deleted;
    struct cell_5 *next_5;
    LinkedList_5 *sublist;
} cell_5;

void allocate_cell_5(cell_5 **p);
void free_cell_5(cell_5 *head);
int value_5(cell_5 *p);
cell_5 *next_5(cell_5 *p);
void ass_val_5(cell_5 *p, int v);
void ass_adr_5(cell_5 *p, cell_5 *q);
void ass_deleted_5(cell_5 *p_5, bool value);
bool deleted_5(cell_5 *p_5);

// Linked List Implementation
struct LinkedList_5
{
    cell_5 *head;
    size_t size;
};

LinkedList_5 *createLinkedList_5();
void destroyLinkedList_5(LinkedList_5 *list);
void addToLinkedList_5(LinkedList_5 *list, int element);
void removeMultiplesLL_5(LinkedList_5 *list, int multiple);
void generatePrimesLinkedList_5(LinkedList_5 *primes, int n);
void createInitialListLinkedList_5(LinkedList_5 *list, int n);
// Function to create a sublist
LinkedList_5 *createSublist();
// Function to add an element to a sublist
void addSublistElement_5(LinkedList_5 *sublist, int value_5);
// Function to destroy a sublist
void destroySublist(LinkedList_5 *sublist);
// Prime Factorization
void factorizeNumber_5(int number, LinkedList_5 *initialList);
void printList_5(LinkedList_5 *list);
// Function to check if two numbers are coprime
bool areCoprime_5(LinkedList_5 *divisors1, LinkedList_5 *divisors2);
// Function to check if two numbers are coprime based on their divisors sublist
bool areCoprimeLinkedList_5(LinkedList_5 *sublist1, LinkedList_5 *sublist2);
// Module to print coprime pairs
void printCoprimePairs_5(LinkedList_5 *list, int n);


#endif
