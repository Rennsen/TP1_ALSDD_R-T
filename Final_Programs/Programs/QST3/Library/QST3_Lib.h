// Linked List Abstract Machine Library
#ifndef QST3LIB_H
#define QST3LIB_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct cell
{
    int value;
    bool deleted;
    struct cell *next;
    int rangeIndex; // New field to keep track of the range index
} cell;

void allocate_cell(cell **p);
void free_cell(cell *head);
int value(cell *p);
cell *next(cell *p);
void ass_val(cell *p, int v);
void ass_adr(cell *p, cell *q);

void ass_range_index(cell *p, int index); // New function to assign range index

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
void generatePrimesLinkedList(LinkedList *primes, int n);
void indexByRange(LinkedList *primes, int range);
void displayByRange(LinkedList *primes, int range);
void printListLogic(cell *head);
void printList(cell *head);

#endif