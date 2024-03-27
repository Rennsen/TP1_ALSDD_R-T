#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QST5.h"

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
