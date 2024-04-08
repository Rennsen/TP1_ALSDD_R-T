#include "graphicInterface.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../Library_Implementation/QST1/Library/QST1_Lib.h"
#include "../Library_Implementation/QST2/Library/DynamicArrayLib.h"
#include "../Library_Implementation/QST2/Library/LinkedListLib.h"
#include "../Library_Implementation/QST3/Library/QST3_LiB.h"
#include "../Library_Implementation/QST4/Library/QST4_LiB.h"
#include "../Library_Implementation/QST5/Library/QST5_Lib.h"

void clearScreen() {
    system("cls");
}

int main() {
    int key;
    int n;
    char continueChoice;
    Presentation();
    welcome();
    do {
        key = 0;
        printf("\n");
        system('cls');
        MENU(&key);
        system('cls');

        switch (key) {
            case 1:
                // Clear the screen
                clearScreen();

                // Display the user's selection
                printf("You selected: The searching algorithm\n\n");

                // Call the function for the searching algorithm
                SearchingPrimeAlgorithm();

                // Prompt the user to enter the upper limit
                printf("\n");
                while (1) {
                 printf("Enter the upper limit (n): ");
                if (scanf("%d", &n) == 1) {
                    // Input is a valid integer
                    break;
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Please enter an integer.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');
                }
                }
                // Display the prime numbers up to the entered upper limit
                printf("Prime numbers up to %d: ", n);
                searchPrimesRecursive(n, 2);
                printf("\n");
                printf("\n");
                printf("\n");

                // Display a separator
                printf("****************************************************************");
                printf("\n");
                break;
            case 2:

                // Clear the screen
                clearScreen();
                int printCountD=0;
                int countD=0;
                // Display the user's selection
                printf("You selected: Search for prime numbers using the Dynamic array\n\n");

                // Call the function for searching prime numbers using Dynamic array
                PrimeSearchDynamicArray();

                // Prompt the user to enter the upper bound
                printf("\n");
                while (1) {
                 printf("Enter the upper limit (n): ");
                if (scanf("%d", &n) == 1) {
                    // Input is a valid integer
                    break;
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Please enter an integer.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');
                }
                }

                // Initialize a dynamic array for the initial list
                DynArrMachine *initialArr;
                initDynArray(&initialArr, n - 1);
                createInitialListDynamicArray(initialArr, n,&countD);

                // Display the initial list
                printf("\nInitial List (Dynamic Array): ");
                printDynamicArray(initialArr,&printCountD);
                printf("\n");

                // Initialize a dynamic array for the prime numbers
                DynArrMachine *dynamicPrimes;
                initDynArray(&dynamicPrimes, 10);

                // Generate prime numbers using Dynamic array
                generatePrimesDynamicArray(dynamicPrimes, n,&countD);

                // Display the prime numbers using Dynamic array
                printf("\nPrimes using Dynamic Array: ");
                printDynamicArray(dynamicPrimes,&printCountD);
                // Free the memory allocated for the dynamic array of prime numbers
                freeDynArray(dynamicPrimes);
                freeDynArray(initialArr);
                printf("\n\n");
                printf("For Question 6 : \n");
                printf("---------------------\n\n");
                printf("The Number Of Iterations Is : : %d",countD);
                printf("\n\n");
                printf("The Total Number Of Iterations With Printing Modules : %d",countD+printCountD);
                // Display a separator
                printf("\n");
                printf("\n");
                printf("\n");
                printf("****************************************************************");
                printf("\n");
                break;
            case 3:
                // Clear the screen
                clearScreen();
                int count=0;
                int PrintCount=0;
                // initializing the number of iterations to 0
                // Display the user's selection
                printf("You selected: Search for the prime numbers using Linked Lists\n\n");

                // Call the function for searching prime numbers using Linked Lists
                PrimeSearchLinkedLists();

                // Prompt the user to enter the upper bound
                printf("\n");
                while (1) {
                 printf("Enter the upper limit (n): ");
                if (scanf("%d", &n) == 1) {
                    // Input is a valid integer
                    break;
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Please enter an integer.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');
                }
                }
                // Create a linked list for the initial list
                LinkedList_2 *initialListLL = createLinkedList_2();
                createInitialListLinkedList_2(initialListLL, n ,&count);

                // Display the initial list
                printf("\nInitial List (Linked List): ");
                printList_2(initialListLL->head,&PrintCount);

                // Create a linked list for the prime numbers
                LinkedList_2 *linkedListPrimes = createLinkedList_2();

                // Generate prime numbers using Linked List
                generatePrimesLinkedList_2(linkedListPrimes, n , &count);

                // Display the prime numbers using Linked List
                printf("\n");
                printf("\nPrimes using Linked List: ");
                printListLogic_2(linkedListPrimes->head,&PrintCount);
                printf("\n\n");
                printf("\n\n");
                // Destroy the linked list of prime numbers to free memory
                destroyLinkedList_2(linkedListPrimes);
                destroyLinkedList_2(initialListLL);
                printf("\n\n");
                printf("For Question 6 : \n");
                printf("---------------------\n\n");
                printf("The Number Of Iterations Is : %d",count);
                printf("\n\n");
                printf("The Total Number Of Iterations With Printing Modules : %d",count+PrintCount);
                // Display a separator
                printf("\n");
                printf("\n");
                printf("\n");
                printf("****************************************************************");
                printf("\n");
                break;
           case 4:
                // Clear the screen
                clearScreen();

                // Display the user's selection
                printf("You selected: Printing prime numbers between two values\n\n");

                // Call the function for printing prime numbers between two values
                PrimeListIndexing();

                // Variables for user input
                int n;
                int range;
                int start;
                int end;

                // Prompt the user to enter the upper bound
                printf("\n");
                while (1) {
                 printf("Enter the upper limit (n): ");
                if (scanf("%d", &n) == 1) {
                    // Input is a valid integer
                    break;
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Please enter an integer.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');
                }
                }
                printf("-------------------------");
                printf("\n");
                printf("\n");

                // Prompt the user to enter the range
                printf("Enter the range: ");
                scanf("%d", &range);
                printf("\n");

                // Create a linked list for storing prime numbers up to the upper bound
                LinkedList_3 *primesList = createLinkedList_3();
                generatePrimesLinkedList_3(primesList, n);

                // Display prime numbers in the range [1, n]
                printf("\nPrime numbers in the range [1, %d]:\n", n);
                printf("\n");
                printf("Prime numbers list: ");
                cell_3 *current = primesList->head;
                printListLogic_3(primesList->head);

                // Create access points for the prime numbers list
                printf("\n\n");
                createAccessPoints_3(primesList, range);
                displayAccessPoints_3(primesList);

                // Prompt the user to enter the start and end of the interval
                printf("\n");
                printf("Enter the start of interval: ");
                scanf("%d", &start);
                printf("\n");
                printf("Enter the end of interval: ");
                scanf("%d", &end);

                // Search for prime numbers in the interval [start, end]
                printf("\n");
                searchPrimesInInterval_3(primesList, start, end);

                // Destroy the linked list of prime numbers to free memory
                destroyLinkedList_3(primesList);
                // Display a separator
                printf("\n");
                printf("\n");
                printf("\n");
                printf("****************************************************************");
                printf("\n");
                break;

      case 5:
                // Clear the screen
                clearScreen();

                // Display the user's selection
                printf("You selected: Expressing each number of the initial list as a product of prime numbers\n\n");

                PrimeProduct();
                // Display a prompt for the upper bound
                printf("\n");
                while (1) {
                 printf("Enter the upper limit (n): ");
                if (scanf("%d", &n) == 1) {
                    // Input is a valid integer
                    break;
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Please enter an integer.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');
                }
                }

                // Create and display the initial list using linked list
                LinkedList_4 *initialListLL_4 = createLinkedList_4();
                createInitialListLinkedList_4(initialListLL_4, n);

                // Generate primes using linked list
                LinkedList_4 *linkedListPrimes_4 = createLinkedList_4();
                generatePrimesLinkedList_4(linkedListPrimes_4, n);

                // Factorization and storing as sublists
                cell_4 *current_4 = initialListLL_4->head_4;
                while (current_4 != NULL)
                {
                    int number_4 = value_4(current_4);
                    factorizeNumber_4(number_4, linkedListPrimes_4, initialListLL_4);
                    current_4 = next_4(current_4);
                }

                // Displaying factorization
                printf("\n");
                printf("Prime Factorization for each number:\n");
                printFactorisation_4(initialListLL_4->head_4);

                // Free memory
                destroyLinkedList_4(initialListLL_4);
                destroyLinkedList_4(linkedListPrimes_4);

                // Display a separator
                printf("\n");
                printf("****************************************************************");
                printf("\n");
                printf("\n");
                break;
          case 6:
                // Clear the screen
                clearScreen();

                // Display the user's selection
                printf("You selected: Find the Co-prime numbers\n\n");

                // Call the function for finding Co-prime numbers
                Coprime();

                // Display a prompt for the upper bound
                printf("\n");
                printf("\n");
                while (1) {
                 printf("Enter the upper limit (n): ");
                if (scanf("%d", &n) == 1) {
                    // Input is a valid integer
                    break;
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Please enter an integer.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');
                }
                }

                // Create and display initial list using linked list
                LinkedList_5 *initialListLL_5 = createLinkedList_5();
                createInitialListLinkedList_5(initialListLL_5, n);

                // Generate primes using linked list
                LinkedList_5 *linkedListPrimes_5 = createLinkedList_5();
                generatePrimesLinkedList_5(linkedListPrimes_5, n);

                // Factorization and storing as sublists
                cell_5 *current_5 = initialListLL_5->head;
                while (current_5 != NULL)
                {
                    int number = value_5(current_5);
                    factorizeNumber_5(number, initialListLL_5);
                    current_5 = next_5(current_5);
                }

                // Display the initial list
                printf("this is the first integer list :");
                printList_5(initialListLL_5);

                // Display the Co-prime numbers pairs
                printf("The co-prime numbers pairs :  ");
                printCoprimePairs_5(initialListLL_5, n);

                // Destroy linked lists to free memory
                destroyLinkedList_5(initialListLL_5);
                destroyLinkedList_5(linkedListPrimes_5);

                // Display a separator
                printf("\n");
                printf("****************************************************************");
                printf("\n");
                printf("\n");
                break;
            case 0:
                // Display a message indicating that the program is exiting
                printf("\n\n\n");
                printf("EXITING THE PROGRAM...\n\n\n");
                printf("Do you want to continue and exit the program ? (Press 'Y' to continue): ");
                scanf(" %c", &continueChoice);
                 if (continueChoice == 'Y' || continueChoice =='y' ) {
                    key = 0; // Set key to 0 to exit the do-while loop
                }else{
                    key=2;
                }
                // Clear the screen
                clearScreen();
                // Display separators and empty lines
                printf("\n");
                printf("\n");
                printf("\n");
                printf("****************************************************************");
                printf("\n");
                printf("\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
        // Prompt the user to continue or exit the program
        printf("\n");
        if(key!=0){    printf("hello world");
            printf("Do you want to continue? (Press 'Y' to continue running the Program): ");
            scanf(" %c", &continueChoice);

        }

        // Read the user's choice

        // Clear the screen
        clearScreen();
        system('cls');

                // Check if the user wants to exit the program
        if (continueChoice != 'Y' && continueChoice !='y' ) {
            key = 0; // Set key to 0 to exit the do-while loop
        }

        // Clear the screen
        clearScreen();
        } while (key != 0); // Continue looping if key is not 0

        // Display a farewell message or perform any necessary cleanup
        GoodBye();

        // Return 0 to indicate successful program execution
        return 0;
}

