#include "LinkedListLib.h"

// Abstract Machine Implementation

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

void ass_val(cell *p, int v)
{
    if (p != NULL)
    {
        p->value = v;
    }
}

void ass_adr(cell *p, cell *q)
{
    if (p != NULL)
    {
        p->next = q;
    }
}

// Linked List Implementation

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

void printListLogic(cell *head)
{
    cell *current = head;
    while (current != NULL)
    {
        if (!current->deleted)
        {
            printf("%d ", value(current));
        }
        current = next(current);
    }
}

void printList(cell *head)
{
    cell *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}
