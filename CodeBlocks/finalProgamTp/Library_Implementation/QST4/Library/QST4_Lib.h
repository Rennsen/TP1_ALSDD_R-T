#ifndef QST4_LIB_H
#define QST4_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LinkedList_4 LinkedList_4;

typedef struct cell_4
{
    int value_4;
    bool deleted_4;
    struct cell_4 *next_4;
    LinkedList_4 *sublist_4;
} cell_4;

// Abstract Machine
void allocate_cell_4(cell_4 **p_4);
void free_cell_4(cell_4 *head_4);
int value_4(cell_4 *p_4);
cell_4 *next_4(cell_4 *p_4);
void ass_val_4(cell_4 *p_4, int v_4);
void ass_adr_4(cell_4 *p_4, cell_4 *q_4);
bool deleted_4(cell_4 *p_3);
void ass_deleted_4(cell_4 *p_3, bool value);
// Linked List
struct LinkedList_4
{
    cell_4 *head_4;
    size_t size_4;
};

LinkedList_4 *createLinkedList_4();
void destroyLinkedList_4(LinkedList_4 *list_4);
void addToLinkedList_4(LinkedList_4 *list_4, int element_4);
void removeMultiplesLL_4(LinkedList_4 *list_4, int multiple_4);
void generatePrimesLinkedList_4(LinkedList_4 *primes_4, int n_4);
void createInitialListLinkedList_4(LinkedList_4 *list_4, int n_4);
// Function to create a sublist
LinkedList_4 *createSublist_4();
// Function to add an element to a sublist
void addSublistElement_4(LinkedList_4 *sublist_4, int value_4);
// Function to destroy a sublist
void destroySublist_4(LinkedList_4 *sublist_4);
// Prime Factorization
void factorizeNumber_4(int number_4, LinkedList_4 *primeList_4, LinkedList_4 *initialList_4);
void printFactorisation_4(cell_4 *head_4);



#endif
