#include "QST4_Lib.h"

// Allocates memory for a cell_4 struct
void allocate_cell_4(cell_4 **p_4) {
    *p_4 = (cell_4 *)malloc(sizeof(cell_4));
}

// Frees the memory used by a linked list of cell_4 structs
void free_cell_4(cell_4 *head_4) {
    while (head_4 != NULL) {
        cell_4 *p_4 = head_4;
        head_4 = head_4->next_4;
        free(p_4);
    }
}

// Returns the value of a cell_4 struct
int value_4(cell_4 *p_4) {
    if (p_4 != NULL) {
        return p_4->value_4;
    } else {
        // Handle NULL pointer case, return an error value.
        perror("Error.");
        return -1;
    }
}

// Returns the next cell_4 struct in the linked list
cell_4 *next_4(cell_4 *p_4) {
    if (p_4 != NULL) {
        return p_4->next_4;
    } else {
        // Handle NULL pointer case, return NULL.
        perror("Error.");
        return NULL;
    }
}

// Sets the value of a cell_4 struct
void ass_val_4(cell_4 *p_4, int v_4) {
    if (p_4 != NULL) {
        p_4->value_4 = v_4;
    }
}

// Sets the next pointer of a cell_4 struct
void ass_adr_4(cell_4 *p_4, cell_4 *q_4) {
    if (p_4 != NULL) {
        p_4->next_4 = q_4;
    }
}


// Gets the deleted flag of a cell_3 struct
bool deleted_4(cell_4 *p_4) {
    if (p_4 != NULL) {
        return p_4->deleted_4;
    } else {
        // Handle NULL pointer case, return false.
        perror("Error.");
        return false;
    }
}

// Sets the deleted flag of a cell_4 struct
void ass_deleted_4(cell_4 *p_4, bool value) {
    if (p_4 != NULL) {
        p_4->deleted_4 = value;
    }
}

// Creates a new LinkedList_4 struct
LinkedList_4 *createLinkedList_4() {
    LinkedList_4 *list_4 = (LinkedList_4 *)malloc(sizeof(LinkedList_4));
    list_4->head_4 = NULL;
    list_4->size_4 = 0;
    return list_4;
}

// Destroys a LinkedList_4 struct
void destroyLinkedList_4(LinkedList_4 *list_4) {
    free_cell_4(list_4->head_4);
    free(list_4);
}

// Adds an element to the linked list
void addToLinkedList_4(LinkedList_4 *list_4, int element_4) {
    // Create a new cell for the element
    cell_4 *newCell_4;
    allocate_cell_4(&newCell_4); // allocating memory for a new cell
    ass_val_4(newCell_4, element_4); // Assign the value to the new cell
    ass_deleted_4(newCell_4, false); // Mark the cell as not deleted
    ass_adr_4(newCell_4, NULL); // Set the address of the next cell to NULL

    // If the list is empty, set the new cell as the head of the list
    if (list_4->head_4 == NULL) {
        list_4->head_4 = newCell_4;
    } else {
        // Otherwise, find the last cell in the list
        cell_4 *current_4 = list_4->head_4;
        while (next_4(current_4) != NULL) {
            current_4 = next_4(current_4);
        }
        // Set the address of the last cell to the new cell
        ass_adr_4(current_4, newCell_4);
    }

    // Increase the size of the list
    list_4->size_4++;
}

// Removes all multiples of a given number (except the number itself) from the linked list
void removeMultiplesLL_4(LinkedList_4 *list_4, int multiple_4) {
    // Start from the head of the list
    cell_4 *current_4 = list_4->head_4;

    // Iterate through each cell in the list
    while (current_4 != NULL) {
        // Check if the current cell is not deleted, its value is a multiple of 'multiple_4', and its value is not 'multiple_4' itself
        if (!deleted_4(current_4) && value_4(current_4) % multiple_4 == 0 && value_4(current_4) != multiple_4) {
            // If the conditions are met, mark the cell as deleted
            current_4->deleted_4 = true;
        }
        // Move to the next cell in the list
        current_4 = next_4(current_4);
    }
}

// Generates a linked list of prime numbers up to the given limit
void generatePrimesLinkedList_4(LinkedList_4 *primes_4, int n_4) {
    // Add the first prime number, 2, to the linked list
    addToLinkedList_4(primes_4, 2);

    // Iterate through odd numbers starting from 3 up to n
    for (int i_4 = 3; i_4 <= n_4; i_4 += 2) {
        // Add each odd number to the linked list
        addToLinkedList_4(primes_4, i_4);
    }

    // Start from the head of the list
    cell_4 *current_4 = primes_4->head_4;

    // Iterate through each prime number in the list
    while (current_4 != NULL) {
        // Get the value of the current prime number
        int currentPrime_4 = value_4(current_4);

        // If the square of the current prime number is greater than n, exit the loop
        if (currentPrime_4 * currentPrime_4 > n_4) {
            break;
        }

        // Remove multiples of the current prime number from the list
        removeMultiplesLL_4(primes_4, currentPrime_4);

        // Move to the next prime number in the list
        current_4 = next_4(current_4);
    }
}

// Creates a linked list of numbers from 2 to n
void createInitialListLinkedList_4(LinkedList_4 *list_4, int n_4) {
    for (int i_4 = 2; i_4 <= n_4; i_4++) {
        addToLinkedList_4(list_4, i_4);
    }
}

// Creates a new sublist of the LinkedList_4
LinkedList_4 *createSublist_4() {
    return createLinkedList_4();
}

// Adds an element to the sublist of the LinkedList_4
void addSublistElement_4(LinkedList_4 *sublist_4, int value_4) {
    addToLinkedList_4(sublist_4, value_4);
}

// Destroys the sublist of the LinkedList_4
void destroySublist_4(LinkedList_4 *sublist_4) {
    destroyLinkedList_4(sublist_4);
}

// Factorizes a given number using the prime numbers in the primeList_4 and the initial list in initialList_4
void factorizeNumber_4(int number_4, LinkedList_4 *primeList_4, LinkedList_4 *initialList_4) {
    LinkedList_4 *primeFactorsList_4 = createLinkedList_4(); // Create a new list to store the prime factors
    int num_4 = number_4;

    cell_4 *currentPrime_4 = primeList_4->head_4;
    while (currentPrime_4 != NULL && num_4 > 1) {
        int prime_4 = value_4(currentPrime_4);
        while (num_4 % prime_4 == 0) {
            addToLinkedList_4(primeFactorsList_4, prime_4); // Add the prime factor to the primeFactorsList_4
            num_4 /= prime_4;
        }
        currentPrime_4 = next_4(currentPrime_4);
    }

    cell_4 *initialListCell_4 = initialList_4->head_4;
    while (initialListCell_4 != NULL) {
        if (value_4(initialListCell_4) == number_4) {
            initialListCell_4->sublist_4 = primeFactorsList_4; // Assign the primeFactorsList_4 to the sublist of the initial list cell
            break;
        }
        initialListCell_4 = next_4(initialListCell_4);
    }
}

// Prints the factorization of the numbers in the linked list
void printFactorisation_4(cell_4 *head_4) {
    cell_4 *current_4 = head_4;
    while (current_4 != NULL) {
        printf("%d: ", value_4(current_4));
        LinkedList_4 *sublist_4 = current_4->sublist_4;
        cell_4 *sublist_current_4 = sublist_4->head_4;
        while (sublist_current_4 != NULL) {
            int count_4 = 0;
            int prime_4 = value_4(sublist_current_4);
            while (sublist_current_4 != NULL && value_4(sublist_current_4) == prime_4) {
                count_4++;
                sublist_current_4 = next_4(sublist_current_4);
            }
            printf("%d", prime_4);
            if (count_4 > 1) {
                printf("^(%d)", count_4);
            }
            if (sublist_current_4 != NULL) {
                printf(" * ");
            }
        }
        printf("\n");
        current_4 = next_4(current_4);
    }
}
