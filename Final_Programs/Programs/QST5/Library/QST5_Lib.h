#ifndef QST5LIB_H
#define QST5LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;
typedef struct cell
{
    int value;
    bool deleted;
    struct cell *next;
    LinkedList *sublist;
} cell;

void allocate_cell(cell **p);
void free_cell(cell *head);
int value(cell *p);
cell *next(cell *p);
void ass_val(cell *p, int v);
void ass_adr(cell *p, cell *q);

// Linked List Implementation
struct LinkedList
{
    cell *head;
    size_t size;
};

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void addToLinkedList(LinkedList *list, int element);
void removeMultiplesLL(LinkedList *list, int multiple);
void generatePrimesLinkedList(LinkedList *primes, int n);
void createInitialListLinkedList(LinkedList *list, int n);
// Function to create a sublist
LinkedList *createSublist();
// Function to add an element to a sublist
void addSublistElement(LinkedList *sublist, int value);
// Function to destroy a sublist
void destroySublist(LinkedList *sublist);
// Prime Factorization
void factorizeNumber(int number, LinkedList *initialList);
void printList(LinkedList *list);
// Function to check if two numbers are coprime
bool areCoprime(LinkedList *divisors1, LinkedList *divisors2);
// Function to check if two numbers are coprime based on their divisors sublist
bool areCoprimeLinkedList(LinkedList *sublist1, LinkedList *sublist2);
// Module to print coprime pairs
void printCoprimePairs(LinkedList *list, int n);

#endif