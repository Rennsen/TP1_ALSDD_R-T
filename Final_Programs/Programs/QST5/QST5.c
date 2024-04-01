#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QST5.h"

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
        factorizeNumber(number, initialListLL);
        current = next(current);
    }



    printf("this is the first integer list :");
    printlist(initialListLL);
    cell *current1 = initialListLL->head;
    int count = 0;
    while (current1 != NULL)
    {
        int number1 = value(current1);
        LinkedList *sublist1 = current1->sublist;
        if (number1 != 1)
        {
            cell *current2 = initialListLL->head;
            while (current2 != NULL)
            {
                int number2 = value(current2);
                if (number1 != number2)
                {
                    LinkedList *sublist2 = current2->sublist;
                    if (areCoprime(sublist1, sublist2))
                    {
                        printf("| (%d,%d) |", number1, number2);
                        count++;
                    }
                }
                current2 = next(current2);
            }
        }

        current1 = next(current1);
    }
    printf("\n");
    printf("1 is co-prime with all the integers in the list.\n");
    printf("Total coprime pairs involving 1: %d\n", count);
}
