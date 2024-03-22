#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Library_Tests/LinkedListLib.h"
#include "../Library_Tests/DynamicArrayLibV2.h"

// Prime Generation
void generatePrimesDynamicArray(DynArrMachine *primes, int n)
{
    addElement(primes, 2); // Add 2 to the dynamic array
    for (int i = 3; i <= n; i += 2)
    {
        addElement(primes, i);
    }

    for (size_t i = 0; i < primes->size; ++i)
    {
        int currentPrime = getValue(primes, i);
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesARR(primes, currentPrime);
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

// Initial List Creation
void createInitialListDynamicArray(DynArrMachine *arr, int n)
{
    for (int i = 2; i <= n; i++)
    {
        addElement(arr, i);
    }
}

void createInitialListLinkedList(LinkedList *list, int n)
{
    for (int i = 2; i <= n; i++)
    {
        addToLinkedList(list, i);
    }
}

// Main Test
int main()
{
    int n;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Create and display initial list using dynamic array
    DynArrMachine *initialList;
    initDynArray(&initialList, n - 1);
    createInitialListDynamicArray(initialList, n);
    printf("Initial List (Dynamic Array): ");
    for (size_t i = 0; i < initialList->size; ++i)
    {
        printf("%d ", getValue(initialList, i));
    }
    printf("\n");

    // Generate primes using dynamic array
    DynArrMachine *dynamicPrimes;
    initDynArray(&dynamicPrimes, 10);
    generatePrimesDynamicArray(dynamicPrimes, n);
    printf("Primes using Dynamic Array: ");
    for (size_t i = 0; i < dynamicPrimes->size; ++i)
    {
        if (!dynamicPrimes->deleted[i])
        {
            printf("%d ", getValue(dynamicPrimes, i));
        }
    }
    printf("\n");
    freeDynArray(dynamicPrimes);

    // Create and display initial list using linked list
    LinkedList *initialListLL = createLinkedList();
    createInitialListLinkedList(initialListLL, n);
    printf("Initial List (Linked List): ");
    cell *current = initialListLL->head;
    while (current != NULL)
    {
        printf("%d ", value(current));
        current = next(current);
    }
    printf("\n");

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);
    printf("Primes using Linked List: ");
    current = linkedListPrimes->head;
    while (current != NULL)
    {
        if (!current->deleted)
        {
            printf("%d ", value(current));
        }
        current = next(current);
    }
    printf("\n");

    destroyLinkedList(linkedListPrimes);
    return 0;
}