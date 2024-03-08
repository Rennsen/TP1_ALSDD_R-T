#include <stdlib.h>
#include <stdio.h>
#include "../Library_Tests/AbstractMachineSingly.h"
#include "QST2_Lib.h"
#include "QST3_Lib.h"

// Main Test
int main()
{
    int n;

    // Get user input for the upper bound
    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Generate primes using dynamic array
    DynamicArray *dynamicPrimes = createDynamicArray(10);
    generatePrimesDynamicArray(dynamicPrimes, n);
    printf("Primes using Dynamic Array: 2 ");
    for (size_t i = 0; i < dynamicPrimes->size; ++i)
    {
        printf("%d ", dynamicPrimes->array[i]);
    }
    printf("\n");
    destroyDynamicArray(dynamicPrimes);

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);
    printf("Primes using Linked List: 2 ");
    cell *current = linkedListPrimes->head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
    IndexListByRange(linkedListPrimes);

    printf("\n");
    destroyLinkedList(linkedListPrimes);
    return 0;
}