#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Library_Tests/LinkedListLib.h"

// Prime Generation
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

// Initial List Creation
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
void factorizeNumber(int number, LinkedList *primeList, LinkedList *initialList)
{
    LinkedList *primeFactorsList = createLinkedList();
    int num = number;

    cell *currentPrime = primeList->head;
    while (currentPrime != NULL && num > 1)
    {
        int prime = value(currentPrime);
        while (num % prime == 0)
        {
            addToLinkedList(primeFactorsList, prime);
            num /= prime;
        }
        currentPrime = next(currentPrime);
    }

    cell *initialListCell = initialList->head;
    while (initialListCell != NULL)
    {
        if (value(initialListCell) == number)
        {
            initialListCell->sublist = primeFactorsList; // Assign sublist to the cell
            break;
        }
        initialListCell = next(initialListCell);
    }
}

// Main Test
int main()
{
    int n;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Create and display initial list using linked list
    LinkedList *initialListLL = createLinkedList();
    createInitialListLinkedList(initialListLL, n);

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);

    // Factorization and storing as sublists
    cell *current = initialListLL->head;
    while (current != NULL)
    {
        int number = value(current);
        factorizeNumber(number, linkedListPrimes, initialListLL);
        current = next(current);
    }

    // Displaying factorization
    printf("Prime Factorization for each number:\n");
    current = initialListLL->head;
    while (current != NULL)
    {
        printf("%d: ", value(current));
        LinkedList *sublist = current->sublist;
        cell *sublist_current = sublist->head;
        while (sublist_current != NULL)
        {
            int count = 0;
            int prime = value(sublist_current);
            while (sublist_current != NULL && value(sublist_current) == prime)
            {
                count++;
                sublist_current = next(sublist_current);
            }
            printf("%d", prime);
            if (count > 1)
            {
                printf("^(%d)", count);
            }
            if (sublist_current != NULL)
            {
                printf(" * ");
            }
        }
        printf("\n");
        current = next(current);
    }

    // Free memory
    destroyLinkedList(initialListLL);
    destroyLinkedList(linkedListPrimes);

    return 0;
}
