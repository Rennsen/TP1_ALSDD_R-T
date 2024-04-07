#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "QST3_Lib.h"


// abstract machine implementation

void allocate_cell_3(cell_3 **p)
{ // allocate a cell
    *p = (cell_3 *)malloc(sizeof(cell_3));
}

void free_cell_3(cell_3 *head)
{ // free all the cells of the list
    while (head != NULL)
    {
        cell_3 *p = head;
        head = head->next;
        free(p);
    }
}

int value_3(cell_3 *p)
{ // give the value of a cell
    if (p != NULL)
    {
        return p->value;
    }
    else
    {
        // Handle NULL pointer case, return an error value.
        perror("Error: Unable to retrieve cell value.");
        return -1;
    }
}

cell_3 *next_3(cell_3 *p)
{ // give the next cell pointer
    if (p != NULL)
    {
        return p->next;
    }
    else
    {
        // Handle NULL pointer case, return NULL.
        perror("Error: Unable to give the next cell pointer.");
        return NULL;
    }
}

void ass_val_3(cell_3 *p, int v)
{ // assign a value to the cell
    if (p != NULL)
    {
        p->value = v;
    }
}

void ass_adr_3(cell_3 *p, cell_3 *q)
{ // assign a next value to the cell
    if (p != NULL)
    {
        p->next = q;
    }
}

bool deleted_3(cell_3 *p_3) {
    if (p_3 != NULL) {
        return p_3->deleted ;
    } else {
        // Handle NULL pointer case, return false.
        perror("Error.");
        return false;
    }
}

// Sets the deleted flag of a cell_3 struct
void ass_deleted_3(cell_3 *p_3, bool value) {
    if (p_3 != NULL) {
        p_3->deleted = value;
    }
}

// Logic Implementation

LinkedList_3 *createLinkedList_3()
{
    LinkedList_3 *list = (LinkedList_3 *)malloc(sizeof(LinkedList_3));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroyLinkedList_3(LinkedList_3 *list)
{
    free_cell_3(list->head); // we free the head then entire list
    free(list);
}

void addToLinkedList_3(LinkedList_3 *list, int element)
{
    cell_3 *newCell;
    allocate_cell_3(&newCell);
    ass_val_3(newCell, element);
    ass_deleted_3(newCell,false);
    ass_adr_3(newCell, NULL);
    if (list->head == NULL)
    {
        list->head = newCell;
    }
    else
    {
        cell_3 *current = list->head;
        while (next_3(current) != NULL)
        {
            current = next_3(current);
        }
        ass_adr_3(current, newCell);
    }
    list->size++;
}

void removeMultiplesLL_3(LinkedList_3 *list, int multiple)
{
    cell_3 *current = list->head;
    while (current != NULL)
    {
        if (!deleted_3(current) && value_3(current) % multiple == 0 && value_3(current) != multiple)
        {
            ass_deleted_3(current,true);
        }
        current = next_3(current);
    }
}

// Prime Generation
void generatePrimesLinkedList_3(LinkedList_3 *primes, int n)
{
    addToLinkedList_3(primes, 2); // Add 2 to the linked list
    for (int i = 3; i <= n; i += 2)
    {
        addToLinkedList_3(primes, i);
    }

    cell_3 *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = value_3(current);
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesLL_3(primes, currentPrime);
        current = next_3(current);
    }
}

void printListLogic_3(cell_3 *head)
{
    cell_3 *current = head;
    while (current != NULL)
    {
        if (!deleted_3(current))
        {
            printf("%d ", value_3(current));
        }
        current = next_3(current);
    }
}


// here ends the generating of the primeList and we start the implementation of the question 3
void createAccessPoints_3(LinkedList_3 *primesList, int range) {
    cell_3 *current = primesList->head;
    AccessPoint_3 *accessPointHead = NULL;
    AccessPoint_3 *accessPointTail = NULL;
    int count = 0;

    while (current != NULL) {
        // Skip over cells with the 'deleted' field set to true
        while (current != NULL && deleted_3(current)) {
            current=next_3(current);
        }

        if (current == NULL) {
            break;
        }

        if (count == 0) {
            AccessPoint_3 *newAP = (AccessPoint_3 *)malloc(sizeof(AccessPoint_3));
            newAP->head = current;
            newAP->next = NULL;
            if (accessPointHead == NULL) {
                accessPointHead = accessPointTail = newAP;
            } else {
                accessPointTail->next = newAP;
                accessPointTail = newAP;
            }
        }

        count++;

        if (count == range) {
            // Find the last non-deleted cell within the current range
            cell_3 *lastCell = current;
            while (next_3(lastCell) != NULL && !deleted_3(next_3(lastCell))) {
                lastCell = next_3(lastCell);
            }
            accessPointTail->tail = lastCell;
            count = 0;
        }

        current = next_3(current);
    }

    if (accessPointTail != NULL) {
        accessPointTail->tail = NULL;
    }

    primesList->accessPoints = accessPointHead;
}  // let us don't consider the deleted cells in the accessPoint, so we don't add the

void searchPrimesInInterval_3(LinkedList_3 *primesList, int start, int end)
{
    bool found = false;
    printf("Prime Numbers within specified interval (%d, %d): ", start, end);

    AccessPoint_3 *current = primesList->accessPoints;
    while (current != NULL)
    {
        cell_3 *head = current->head;
        cell_3 *tail = current->tail;

        if (head == NULL)
        {
            break;
        }

        // If the head value is greater than the end, move to the next AccessPoint
        if (value_3(head) > end)
        {
            current = next_3(current);
            continue;
        }

        // Adjust end to consider the last cell of the last access point
        int adjustedEnd = (tail != NULL && value_3(tail) != -1) ? tail->value : end;

        // Set the start position to the head of the access point
        cell_3 *ptr = head;

        // Iterate over the cells within the access point
        while (ptr != NULL && value_3(ptr) <= adjustedEnd)
        {
            if (value_3(ptr) >= start && value_3(ptr) <= end && !deleted_3(ptr))
            {
                printf("%d ", value_3(ptr));
                found = true;
            }
            ptr = next_3(ptr);
        }

        // Break the loop if the end of the interval has been reached
        if (ptr != NULL && value_3(ptr) > end)
        {
            break;
        }

        current = current->next;
    }

    if (!found)
    {
        printf("No prime numbers found within the specified interval.\n");
    }
    else
    {
        printf("\n");
    }
}

void displayAccessPoints_3(LinkedList_3 *primesList)
{
    printf("Access Points:\n");
    AccessPoint_3 *current = primesList->accessPoints;
    int accessPointIndex = 1;

    while (current != NULL)
    {
        printf("Access Point %d: Head = %d, Tail = %d\n", accessPointIndex, current->head->value, (current->tail ? current->tail->value : -1));
        current = current->next;
        accessPointIndex++;
    }
}

void printList_3(cell_3 *head)
{
    cell_3 *current = head;
    while (current != NULL)
    {
        printf("%d ", value_3(current));
        current = next_3(current);
    }
}

