// Linked List Abstract Machine Library
#ifndef AbstrMachSingly_H
#define AbstrMachSingly_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct cell
{
    int value;
    bool deleted;
    struct cell *next;
} cell;

void allocate_cell(cell **p);
void free_cell(cell *head);
int value(cell *p);
cell *next(cell *p);
void ass_val(cell *p, int v);
void ass_adr(cell *p, cell *q);

// Linked List Implementation
typedef struct LinkedList
{
    cell *head;
    size_t size;
}LinkedList;

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void addToLinkedList(LinkedList *list, int element);
void removeMultiplesLL(LinkedList *list, int multiple);
void generatePrimesLinkedList(LinkedList *primes, int n);
void createInitialListLinkedList(LinkedList *list, int n);
void printListLogic(cell *head);
void printList(cell *head);

#endif