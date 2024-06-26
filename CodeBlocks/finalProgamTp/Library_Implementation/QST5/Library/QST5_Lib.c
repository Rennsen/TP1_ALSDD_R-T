
#include "QST5_Lib.h"

// abstract machine for the linked list

// Allocates memory for a cell_5 struct
void allocate_cell_5(cell_5 **p)
{
    *p = (cell_5 *)malloc(sizeof(cell_5));
}

// Frees the memory used by a linked list of cell_5 structs
void free_cell_5(cell_5 *head)
{
    while (head != NULL)
    {
        cell_5 *p = head;
        head = head->next_5;
        free(p);
    }
}

// Returns the value of a cell_5 struct
int value_5(cell_5 *p)
{
    if (p != NULL)
    {
        return p->value_5;
    }
    else
    {
        // Handle NULL pointer case, return an error value.
        perror("Error.");
        return -1;
    }
}

// Returns the next cell_5 struct in the linked list
cell_5 *next_5(cell_5 *p)
{
    if (p != NULL)
    {
        return p->next_5;
    }
    else
    {
        // Handle NULL pointer case, return NULL.
        perror("Error.");
        return NULL;
    }
}

// Sets the value of a cell_5 struct
void ass_val_5(cell_5 *p, int v)
{
    if (p != NULL)
    {
        p->value_5 = v;
    }
}

// Sets the next pointer of a cell_5 struct
void ass_adr_5(cell_5 *p, cell_5 *q)
{
    if (p != NULL)
    {
        p->next_5 = q;
    }
}

// Gets the deleted flag of a cell_3 struct
bool deleted_5(cell_5 *p_5) {
    if (p_5 != NULL) {
        return p_5->deleted;
    } else {
        // Handle NULL pointer case, return false.
        perror("Error.");
        return false;
    }
}

// Sets the deleted flag of a cell_4 struct
void ass_deleted_5(cell_5 *p_5, bool value) {
    if (p_5 != NULL) {
        p_5->deleted = value;
    }
}

// Linked List Implementation

LinkedList_5 *createLinkedList_5()
{
    LinkedList_5 *list = (LinkedList_5 *)malloc(sizeof(LinkedList_5));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroyLinkedList_5(LinkedList_5 *list)
{
    free_cell_5(list->head); // we destroy the head
    free(list); // the do every cell
}

// adding an element to the list
void addToLinkedList_5(LinkedList_5 *list, int element)
{
    // Create a new cell for the element
    cell_5 *newCell;
    allocate_cell_5(&newCell); // Allocate memory for the new cell
    ass_val_5(newCell, element); // Assign the value to the new cell
    newCell->deleted = false; // Mark the cell as not deleted
    ass_adr_5(newCell, NULL); // Set the address of the next cell to NULL

    // If the list is empty, set the new cell as the head of the list
    if (list->head == NULL)
    {
        list->head = newCell;
    }
    else
    {
        // Otherwise, find the last cell in the list
        cell_5 *current = list->head;
        while (next_5(current) != NULL)
        {
            current = next_5(current);
        }
        // Set the address of the last cell to the new cell
        ass_adr_5(current, newCell);
    }

    // Increase the size of the list
    list->size++;
}


void removeMultiplesLL_5(LinkedList_5 *list, int multiple)
{
    cell_5 *current = list->head;
    while (current != NULL)
    {
        if (!deleted_5(current) && value_5(current) % multiple == 0 && value_5(current) != multiple)
        {
            ass_deleted_5(current,true);

        }
        current = next_5(current);
    }
}

void generatePrimesLinkedList_5(LinkedList_5 *primes, int n)
{
    addToLinkedList_5(primes, 2); // Add 2 to the linked list
    for (int i = 3; i <= n; i += 2)
    {
        addToLinkedList_5(primes, i);
    }

    cell_5 *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = value_5(current);
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesLL_5(primes, currentPrime);
        current = next_5(current);
    }
}

void createInitialListLinkedList_5(LinkedList_5 *list, int n)
{
    for (int i = 2; i <= n; i++)
    {
        addToLinkedList_5(list, i);
    }
}

// Function to create a sublist
LinkedList_5 *createSublist()
{
    return createLinkedList_5();
}

// Function to add an element to a sublist
void addSublistElement(LinkedList_5 *sublist, int value_5)
{
    addToLinkedList_5(sublist, value_5);
}

// Function to destroy a sublist
void destroySublist(LinkedList_5 *sublist)
{
    destroyLinkedList_5(sublist);
}

// Prime Factorization
void factorizeNumber_5(int number, LinkedList_5 *initialList)
{
    // Create a new linked list to store factors of 'number'
    LinkedList_5 *factorsList = createLinkedList_5();

    // Find factors of 'number' and add them to 'factorsList'
    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            addToLinkedList_5(factorsList, i);
        }
    }

    // Find the cell in 'initialList' that corresponds to 'number'
    cell_5 *initialListCell = initialList->head;
    while (initialListCell != NULL)
    {
        if (value_5(initialListCell) == number)
        {
            // Assign the factors list to the 'sublist' field of the cell
            initialListCell->sublist = factorsList;
            break;
        }
        initialListCell = next_5(initialListCell);
    }
}

void printList_5(LinkedList_5 *list)
{
    // Start from the head of the list
    cell_5 *current = list->head;

    // Loop through each element in the list
    while (current != NULL)
    {
        // Print the value of the current element
        printf("%d ", value_5(current));

        // Move to the next element
        current = next_5(current);
    }

    // Print a new line after printing all elements
    printf("\n");
}

// Function to check if two numbers are coprime
bool areCoprime_5(LinkedList_5 *divisors1, LinkedList_5 *divisors2)
{
    cell_5 *current1 = divisors1->head;
    cell_5 *current2 = divisors2->head;

    while (current1 != NULL && current2 != NULL)
    {
        int divisor1 = value_5(current1);
        int divisor2 = value_5(current2);

        if (divisor1 == divisor2)
        {
            return false; // Common divisor found, not coprime
        }
        else if (divisor1 < divisor2)
        {
            current1 = next_5(current1);
        }
        else
        {
            current2 = next_5(current2);
        }
    }

    return true; // No common divisor found, coprime
}

// Function to check if two numbers are coprime based on their divisors sublist
bool areCoprimeLinkedList_5(LinkedList_5 *sublist1, LinkedList_5 *sublist2)
{
    cell_5 *current1 = sublist1->head;
    cell_5 *current2 = sublist2->head;

    while (current1 != NULL && current2 != NULL)
    {
        int divisor1 = value_5(current1);
        int divisor2 = value_5(current2);

        if (divisor1 == divisor2)
        {
            return false; // Common divisor found, not coprime
        }
        else if (divisor1 < divisor2)
        {
            current1 = next_5(current1);
        }
        else
        {
            current2 = next_5(current2);
        }
    }

    return true; // No common divisor found, coprime
}

// Module to print coprime pairs
void printCoprimePairs_5(LinkedList_5 *list, int n)
{
    int count = 0; // Initialize a counter for coprime pairs
    cell_5 *current1 = list->head; // Start from the head of the list
    while (current1 != NULL) // Loop through each element in the list
    {
        int number1 = value_5(current1); // Get the value of the current element
        LinkedList_5 *sublist1 = current1->sublist; // Get the sublist of the current element

        // Check if the current element is not 1
        if (number1 != 1)
        {
            cell_5 *current2 = next_5(current1); // Start from the next element
            while (current2 != NULL) // Loop through each element after the current element
            {
                int number2 = value_5(current2); // Get the value of the next element
                // Check if the two numbers are different
                if (number1 != number2)
                {
                    LinkedList_5 *sublist2 = current2->sublist; // Get the sublist of the next element
                    // Check if the two sublists are coprime
                    if (areCoprime_5(sublist1, sublist2))
                    {
                        // Print the coprime pair and increment the counter
                        printf("| (%d,%d) |", number1, number2);
                        count++;
                    }
                }
                current2 = next_5(current2); // Move to the next element
            }
        }
        current1 = next_5(current1); // Move to the next element
    }
    printf("\n");
    printf("1 is co-prime with all the integers in the list.\n");
    printf("Total co-prime pairs involving 1: %d\n", n-1); // Print the total number of coprime pairs involving 1
}

