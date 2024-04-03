#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Library/LinkedListLib.h"

// Main
int main()
{
    int n;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Create and display initial list using linked list
    LinkedList *initialListLL = createLinkedList();
    createInitialListLinkedList(initialListLL, n);
    printf("Initial List (Linked List): ");
    cell *current = initialListLL->head;
    printList(initialListLL->head);
    printf("\n");

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);
    printf("Primes using Linked List: ");
    current = linkedListPrimes->head;
    printListLogic(linkedListPrimes->head);
    printf("\n");

    destroyLinkedList(linkedListPrimes);
    return 0;
}