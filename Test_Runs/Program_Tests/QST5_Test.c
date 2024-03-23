#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked List Abstract Machine Library
#ifndef AbstrMachSingly_H
#define AbstrMachSingly_H

#include <stdlib.h>
#include <stdio.h>

typedef struct divisors
{
    int divisor;
    struct divisors *next;
} divisors;

typedef struct cell
{
    int value;
    divisors *divisorList;
    struct cell *next;
} cell;

void allocate_divisor(divisors **p)
{
    *p = (divisors *)malloc(sizeof(divisors));
}

void addToDivisorList(cell *p, int divisor)
{
    divisors *newDivisor;
    allocate_divisor(&newDivisor);
    newDivisor->divisor = divisor;
    newDivisor->next = NULL;

    if (p->divisorList == NULL)
    {
        p->divisorList = newDivisor;
    }
    else
    {
        divisors *current = p->divisorList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newDivisor;
    }
}




void allocate_cell(cell **p);
void free_cell(cell *head);
int value(cell *p);
cell *next(cell *p);

void allocate_cell(cell **p)
{
    *p = (cell *)malloc(sizeof(cell));
}

void free_cell(cell *head)
{
    while (head != NULL)
    {
        cell *p = head;
        head = head->next;
        free(p);
    }
}

int value(cell *p)
{
    if (p != NULL)
    {
        return p->value;
    }
    else
    {
        perror("Error.");
        return -1;
    }
}

cell *next(cell *p)
{
    if (p != NULL)
    {
        return p->next;
    }
    else
    {
        perror("Error.");
        return NULL;
    }
}

#endif

// Linked List Implementation
typedef struct LinkedList
{
    cell *head;
    size_t size;
} LinkedList;

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void addToLinkedList(LinkedList *list, int element);
void removeMultiplesLL(LinkedList *list, int multiple);

LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroyLinkedList(LinkedList *list)
{
    free_cell(list->head);
    free(list);
}

void addToLinkedList(LinkedList *list, int element)
{
    cell *newCell;
    allocate_cell(&newCell);
    newCell->value = element;
    newCell->divisorList = NULL;
    newCell->next = NULL;
    if (list->head == NULL)
    {
        list->head = newCell;
    }
    else
    {
        cell *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newCell;
    }
    list->size++;
}


void Access_by_value(cell * head,cell **current,cell **previous,int value){
cell * P;
bool find=false;
P=head;
*previous=NULL;
while((P!=NULL)&&(!find)){
    if (P->value==value){
        find = true;
    }else{
        *previous=P;
        P=P->next;
    }
}
*current=P;
}

void delete_by_value(cell **head,int value){
    cell *current;
    cell *previous;
    Access_by_value(*head,&current,&previous,value);
    if(current!=NULL){
        if(current==*head){
            *head=current->next;
        }else{
            previous->next=current->next;
        }
     free(current);
    }else{
         printf("value doesn't exist int the list");
    }
}

void removeMultiplesLL(LinkedList *list, int multiple)
{
    cell *current = list->head;
    cell *P = list->head;
    while (current != NULL)
    {
        if (current->value % multiple == 0 && current->value != multiple)
        {
           delete_by_value(&P,current->value);
            current = current->next;
        }else{
           current = current->next;
        }
    }
}

// Prime Generation
void generatePrimesLinkedList(LinkedList *primes, int n)
{
    for (int i = 2; i <= n; ++i)
    {
        addToLinkedList(primes, i);
    }
    // adding the integers between 2 and n

    cell *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = current->value;
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesLL(primes, currentPrime); // removing the multiples of the cell value 
        current = current->next;
    }
   
}
// Factorization using Prime List
void factorizeNumbers(LinkedList *primes, int n)
{
    for (int i = 2; i <= n; ++i)
    {
        printf("%d: ", i);
        int num = i;
        cell *current = primes->head;
        while (current != NULL && current->value <= num)
        {
            if (num % current->value == 0)
            {
                addToDivisorList(current, i); // add the divisor to the list of divisors
                printf("%d ", current->value);
                num /= current->value;
            }
            else
            {
                current = current->next;
            }
        }
        printf("\n");
    }
}

// Check if two numbers are co-prime based on their divisor lists
bool areDivisorsCoPrime(cell *cell1, cell *cell2) {
    divisors *div1 = cell1->divisorList;
    divisors *div2 = cell2->divisorList;

    while (div1 != NULL && div2 != NULL) {
        if (div1->divisor == div2->divisor) {
            return false; // If a common divisor is found, numbers are not co-prime
        } else if (div1->divisor < div2->divisor) {
            div1 = div1->next;
        } else {
            div2 = div2->next;
        }
    }

    return true; // If no common divisors are found, numbers are co-prime
}

// Check all co-prime numbers in the linked list
// Check all co-prime numbers in the linked list
void checkCoPrimes(LinkedList *list) {
    cell *current = list->head;
    bool messageDisplayed = false; // Flag to track if message has been displayed

    while (current != NULL) {
        cell *other = current->next;
        while (other != NULL) {
            if (areDivisorsCoPrime(current, other)) {        
                printf("(%d , %d)", current->value, other->value);
            }
            other = other->next;
        }
        current = current->next;
    }

}


void printLinkedList(LinkedList *list) {
    cell *current = list->head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}



int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Create and display initial list using linked list
    LinkedList *primesList = createLinkedList();
    // Generate primes using linked list
    generatePrimesLinkedList(primesList, n);


    printLinkedList(primesList);
    // Check co-prime numbers in the list
    checkCoPrimes(primesList);

    destroyLinkedList(primesList);
    return 0;
}
