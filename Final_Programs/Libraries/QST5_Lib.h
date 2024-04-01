// Linked List Abstract Machine Library
#ifndef QST5LIB_H
#define QST5LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct divisors
{
    int divisor;
    struct divisors *next;
} divisors;

typedef struct cell
{
    int value;
    divisors *divisorList;
    struct cell *next;
} cell;

void allocate_divisor(divisors **p)
{
    *p = (divisors *)malloc(sizeof(divisors));
}

void addToDivisorList(cell *p, int divisor)
{
    divisors *newDivisor;
    allocate_divisor(&newDivisor);
    newDivisor->divisor = divisor;
    newDivisor->next = NULL;

    if (p->divisorList == NULL)
    {
        p->divisorList = newDivisor;
    }
    else
    {
        divisors *current = p->divisorList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newDivisor;
    }
}

void allocate_cell(cell **p);
void free_cell(cell *head);
int value(cell *p);
cell *next(cell *p);

void allocate_cell(cell **p)
{
    *p = (cell *)malloc(sizeof(cell));
}

void free_cell(cell *head)
{
    while (head != NULL)
    {
        cell *p = head;
        head = head->next;
        free(p);
    }
}

int value(cell *p)
{
    if (p != NULL)
    {
        return p->value;
    }
    else
    {
        perror("Error.");
        return -1;
    }
}

cell *next(cell *p)
{
    if (p != NULL)
    {
        return p->next;
    }
    else
    {
        perror("Error.");
        return NULL;
    }
}

#endif

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
    newCell->value = element;
    newCell->divisorList = NULL;
    newCell->next = NULL;
    if (list->head == NULL)
    {
        list->head = newCell;
    }
    else
    {
        cell *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newCell;
    }
    list->size++;
}

void Access_by_value(cell *head, cell **current, cell **previous, int value)
{
    cell *P;
    bool find = false;
    P = head;
    *previous = NULL;
    while ((P != NULL) && (!find))
    {
        if (P->value == value)
        {
            find = true;
        }
        else
        {
            *previous = P;
            P = P->next;
        }
    }
    *current = P;
}

void delete_by_value(cell **head, int value)
{
    cell *current;
    cell *previous;
    Access_by_value(*head, &current, &previous, value);
    if (current != NULL)
    {
        if (current == *head)
        {
            *head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
    }
    else
    {
        printf("value doesn't exist int the list");
    }
}

void removeMultiplesLL(LinkedList *list, int multiple)
{
    cell *current = list->head;
    cell *P = list->head;
    while (current != NULL)
    {
        if (current->value % multiple == 0 && current->value != multiple)
        {
            delete_by_value(&P, current->value);
            current = current->next;
        }
        else
        {
            current = current->next;
        }
    }
}

// Prime Generation
void generatePrimesLinkedList(LinkedList *primes, int n)
{
    for (int i = 2; i <= n; ++i)
    {
        addToLinkedList(primes, i);
    }
    // adding the integers between 2 and n

    cell *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = current->value;
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesLL(primes, currentPrime); // removing the multiples of the cell value
        current = current->next;
    }
}

void createInitialListLinkedList(LinkedList *list, int n) // creation of the first list
{
    for (int i = 2; i <= n; i++)
    {
        addToLinkedList(list, i);
    }
}

void printLinkedList(LinkedList *list)
{
    cell *current = list->head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if two numbers are co-prime
bool areCoPrime(int a, int b)
{
    return gcd(a, b) == 1;
}

void printList(cell* head) {
    cell* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


