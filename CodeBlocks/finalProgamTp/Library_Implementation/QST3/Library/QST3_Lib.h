// Linked List Abstract Machine Library
#ifndef QST3_LIB_H
#define QST3_LIB_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct cell_3
{
    int value;
    bool deleted;
    struct cell_3 *next;
    // int rangeIndex; // New field to keep track of the range index
} cell_3;

typedef struct AccessPoint_3
{
    cell_3 *head;
    cell_3 *tail;
    struct AccessPoint_3 *next;
} AccessPoint_3;

typedef struct LinkedList_3
{
    cell_3 *head;
    AccessPoint_3 *accessPoints;
    size_t size;
} LinkedList_3;

// abstract machine implementation

void allocate_cell_3(cell_3 **p);
void free_cell_3(cell_3 *head);
int value_3(cell_3 *p);
cell_3 *next_3(cell_3 *p);
void ass_val_3(cell_3 *p, int v);
void ass_adr_3(cell_3 *p, cell_3 *q);
void destroyLinkedList_3(LinkedList_3 *list);
void addToLinkedList_3(LinkedList_3 *list, int element);
void removeMultiplesLL_3(LinkedList_3 *list, int multiple);
bool deleted_3(cell_3 *p_3);
void ass_deleted_3(cell_3 *p_3, bool value);


// Prime Generation

void generatePrimesLinkedList_3(LinkedList_3 *primes, int n);
void printListLogic_3(cell_3 *head);
void createAccessPoints_3(LinkedList_3 *primesList, int range);// let us don't consider the deleted cells in the accessPoint, so we don't add the
void searchPrimesInInterval_3(LinkedList_3 *primesList, int start, int end);
void displayAccessPoints_3(LinkedList_3 *primesList);
void printList_3(cell_3 *head);

#endif
