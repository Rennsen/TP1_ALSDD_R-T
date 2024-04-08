#include "LinkedListLib.h"

// Abstract Machine Implementation

// Allocates memory for a cell_2 struct
void allocate_cell_2(cell_2 **p) {
    *p = (cell_2 *)malloc(sizeof(cell_2));
}

// Frees the memory used by a linked list of cell_2 structs
void free_cell_2(cell_2 *head) {
    while (head != NULL) {
        cell_2 *p = head;
        head = head->next;
        free(p);
    }
}

// Returns the value of a cell_2 struct
int value_2(cell_2 *p) {
    if (p != NULL) {
        return p->value;
    } else {
        perror("Error.");
        return -1;
    }
}

// Returns the next cell_2 struct in the linked list
cell_2 *next_2(cell_2 *p) {
    if (p != NULL) {
        return p->next;
    } else {
        perror("Error.");
        return NULL;
    }
}

// Sets the value of a cell_2 struct
void ass_val_2(cell_2 *p, int v) {
    if (p != NULL) {
        p->value = v;
    }
}

// Sets the next pointer of a cell_2 struct
void ass_adr_2(cell_2 *p, cell_2 *q) {
    if (p != NULL) {
        p->next = q;
    }
}

// Gets the deleted flag of a cell_2 struct
bool deleted_2(cell_2 *p) {
    if (p != NULL) {
        return p->deleted;
    } else {
        perror("Error.");
        return false;
    }
}

// Sets the deleted flag of a cell_2 struct
void ass_deleted_2(cell_2 *p, bool value) {
    if (p != NULL) {
        p->deleted = value;
    }
}

// Linked List Implementation

// Creates a new LinkedList_2 struct
LinkedList_2 *createLinkedList_2() {
    LinkedList_2 *list = (LinkedList_2 *)malloc(sizeof(LinkedList_2));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Destroys a LinkedList_2 struct
void destroyLinkedList_2(LinkedList_2 *list) {
    free_cell_2(list->head);
    free(list);
}

// Adds an element to the linked list
void addToLinkedList_2(LinkedList_2 *list, int element ,int *count) {
    cell_2 *newCell;
    allocate_cell_2(&newCell);
    ass_val_2(newCell, element);
    ass_deleted_2(newCell, false);
    ass_adr_2(newCell, NULL);

    if (list->head == NULL) {
        list->head = newCell;
    } else {
        cell_2 *current = list->head;
        while (next_2(current) != NULL) {
            current = next_2(current);
            *count+=1;
        }
        ass_adr_2(current, newCell);
    }

    list->size++;
}

// Removes all multiples of a given number (except the number itself) from the linked list
void removeMultiplesLL_2(LinkedList_2 *list, int multiple,int *count) {
    cell_2 *current = list->head;
    while (current != NULL) {
        if (!deleted_2(current) && value_2(current) % multiple == 0 && value_2(current) != multiple) {
            ass_deleted_2(current, true);
        }
        *count+=1;
        current = next_2(current);
    }
}

// Generates a linked list of prime numbers up to the given limit
void generatePrimesLinkedList_2(LinkedList_2 *primes, int n ,int *count) {
    addToLinkedList_2(primes, 2,count); // Add 2 to the linked list

    // Add all odd numbers from 3 to n
    for (int i = 3; i <= n; i += 2) {
        addToLinkedList_2(primes, i,count);
        *count+=1;
    }

    // Remove all multiples of each prime number from the list
    cell_2 *current = primes->head;
    while (current != NULL) {
        int currentPrime = value_2(current);
        if (currentPrime * currentPrime > n) {
            break;
        }
        removeMultiplesLL_2(primes, currentPrime , count);
        current = next_2(current);
        *count+=1;
    }
}

// Creates a linked list of numbers from 2 to n
void createInitialListLinkedList_2(LinkedList_2 *list, int n , int *count) {
    for (int i = 2; i <= n; i++) {
        addToLinkedList_2(list, i, count);
        *count+=1;
    }
}

// Prints the non-deleted elements of a linked list
void printListLogic_2(cell_2 *head,int *count) {
    cell_2 *current = head;
    while (current != NULL) {
        if (!deleted_2(current)) {
            printf("| %d |", value_2(current));
        }
        current = next_2(current);
        *count+=1;
    }
}

// Prints all the elements of a linked list
void printList_2(cell_2 *head,int *count) {
    cell_2 *current = head;
    while (current != NULL) {
        printf("| %d |", value_2(current));
        current = next_2(current);
        *count+=1;
    }
}
