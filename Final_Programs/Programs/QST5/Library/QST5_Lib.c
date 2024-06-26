#include "QST5_Lib.h"

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
void factorizeNumber(int number, LinkedList *initialList)
{
    LinkedList *factorsList = createLinkedList();

    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            addToLinkedList(factorsList, i);
        }
    }

    cell *initialListCell = initialList->head;
    while (initialListCell != NULL)
    {
        if (value(initialListCell) == number)
        {
            initialListCell->sublist = factorsList; // Assign sublist to the cell
            break;
        }
        initialListCell = next(initialListCell);
    }
}

void printList(LinkedList *list)
{
    cell *current = list->head;
    while (current != NULL)
    {
        printf("%d ", value(current));
        current = next(current);
    }
    printf("\n");
}

// Function to check if two numbers are coprime
bool areCoprime(LinkedList *divisors1, LinkedList *divisors2)
{
    cell *current1 = divisors1->head;
    cell *current2 = divisors2->head;

    while (current1 != NULL && current2 != NULL)
    {
        int divisor1 = value(current1);
        int divisor2 = value(current2);

        if (divisor1 == divisor2)
        {
            return false; // Common divisor found, not coprime
        }
        else if (divisor1 < divisor2)
        {
            current1 = next(current1);
        }
        else
        {
            current2 = next(current2);
        }
    }

    return true; // No common divisor found, coprime
}

// Function to check if two numbers are coprime based on their divisors sublist
bool areCoprimeLinkedList(LinkedList *sublist1, LinkedList *sublist2)
{
    cell *current1 = sublist1->head;
    cell *current2 = sublist2->head;

    while (current1 != NULL && current2 != NULL)
    {
        int divisor1 = value(current1);
        int divisor2 = value(current2);

        if (divisor1 == divisor2)
        {
            return false; // Common divisor found, not coprime
        }
        else if (divisor1 < divisor2)
        {
            current1 = next(current1);
        }
        else
        {
            current2 = next(current2);
        }
    }

    return true; // No common divisor found, coprime
}

// Module to print coprime pairs
void printCoprimePairs(LinkedList *list, int n)
{
    cell *current1 = list->head;
    while (current1 != NULL)
    {
        int number1 = value(current1);
        LinkedList *sublist1 = current1->sublist;
        if (number1 != 1)
        {
            cell *current2 = next(current1);
            while (current2 != NULL)
            {
                int number2 = value(current2);
                if (number1 != number2)
                {
                    LinkedList *sublist2 = current2->sublist;
                    if (areCoprime(sublist1, sublist2))
                    {
                        printf("| (%d,%d) |", number1, number2);
                    }
                }
                current2 = next(current2);
            }
        }
        current1 = next(current1);
    }
    printf("\n");
    printf("1 is co-prime with all the integers in the list.\n");
    printf("Total coprime pairs involving 1: %d\n", n - 1);
}