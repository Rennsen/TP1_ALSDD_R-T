// Linked List Abstract Machine Library
#ifndef AbstrMachSingly_H
#define AbstrMachSingly_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct cell_2
{
    int value;
    bool deleted;
    struct cell_2 *next;
} cell_2;

void allocate_cell_2(cell_2 **p);
void free_cell_2(cell_2 *head);
int value_2(cell_2 *p);
cell_2 *next_2(cell_2 *p);
void ass_val_2(cell_2 *p, int v);
void ass_adr_2(cell_2 *p, cell_2 *q);
bool deleted_2(cell_2 *p);
void ass_deleted_2(cell_2 *p, bool value);

// Linked List Implementation
typedef struct LinkedList_2
{
    cell_2 *head;
    size_t size;
}LinkedList_2;

LinkedList_2 *createLinkedList_2();
void destroyLinkedList_2(LinkedList_2 *list);
void addToLinkedList_2(LinkedList_2 *list, int element, cell_2 **lastCell, int *count);
void removeMultiplesLL_2(LinkedList_2 *list, int multiple);
void generatePrimesLinkedList_2(LinkedList_2 *primes, int n,int *count);
void createInitialListLinkedList_2(LinkedList_2 *list, int n,int *count);
void printListLogic_2(cell_2 *head,int *count);
void printList_2(cell_2 *head,int *count);


#endif // AbstrMachSingly_H
