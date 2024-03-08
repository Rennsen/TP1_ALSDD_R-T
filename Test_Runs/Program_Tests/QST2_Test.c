#include <stdlib.h>
#include <stdio.h>
#include "../Library_Tests/AbstractMachineSingly.h"

// Structures
typedef struct DynamicArray
{
    int *array;
    size_t size;
    size_t capacity;
} DynamicArray;

// Pointer to cell structure in the library
typedef struct LinkedList
{
    cell *head;
    size_t size;
} LinkedList;

// Headers
// Dynamic Array
DynamicArray *createDynamicArray(size_t initialCapacity);
void destroyDynamicArray(DynamicArray *arr);
void addToDynamicArray(DynamicArray *arr, int element);
void removeMultiplesARR(DynamicArray *arr, int multiple);

// Linked List
LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void addToLinkedList(LinkedList *list, int element);
void removeMultiplesLL(LinkedList *list, int multiple);

// Generation Of Prime Numbers
void generatePrimesDynamicArray(DynamicArray *primes, int n);
void generatePrimesLinkedList(LinkedList *primes, int n);

// Implementation
// Dynamic Array Implementation
DynamicArray *createDynamicArray(size_t initialCapacity)
{
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->array = (int *)malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

void destroyDynamicArray(DynamicArray *arr)
{
    free(arr->array);
    free(arr);
}

void addToDynamicArray(DynamicArray *arr, int element)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
    }
    arr->array[arr->size++] = element;
}

void removeMultiplesARR(DynamicArray *arr, int multiple)
{
    // Remove multiples of 'multiple' from the dynamic array
    size_t i = 0;
    while (i < arr->size)
    {
        if ((arr->array[i] % multiple == 0) && (arr->array[i] != multiple))
        {
            // Shift elements to remove the multiple
            for (size_t j = i; j < arr->size - 1; ++j)
            {
                arr->array[j] = arr->array[j + 1];
            }
            arr->size--;
        }
        else
        {
            i++;
        }
    }
}

// Linked List Implementation
LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void destroyLinkedList(LinkedList *list)
{
    cell *current = list->head;
    cell *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void addToLinkedList(LinkedList *list, int element)
{
    cell *newcell = (cell *)malloc(sizeof(cell));
    newcell->value = element;
    newcell->next = NULL;

    // If the list is empty, we set the newcell to head
    if(list->head == NULL) {
        list->head = newcell;
    } else {
        // Go through list to find the last element
        cell *current = list->head;
        while (current->next != NULL){
            current = current->next;
        }
        // Append newcell to the last element
        current->next = newcell;
    }
    list->size++;
}

void removeMultiplesLL(LinkedList *list, int multiple)
{
    cell *current = list->head;
    cell *prev = NULL;

    while (current != NULL)
    {
        if (current->value % multiple == 0 && current->value != multiple)
        {
            cell *temp = current;
            // if (prev == NULL)
            // {
            //     list->head = current->next;
            //     current = current->next;
            // }
            // else
            // {
            prev->next = current->next;
            current = current->next;
            // }
            free(temp);
            list->size--;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

// Prime Generation
void generatePrimesDynamicArray(DynamicArray *primes, int n)
{
    // Add odd numbers up to n
    for (int i = 3; i <= n; i += 2)
    {
        addToDynamicArray(primes, i);
    }

    // Apply the multiple method to remove non-prime numbers
    for (size_t i = 0; i < primes->size; ++i)
    {
        int currentPrime = primes->array[i];
        if (currentPrime * currentPrime > n)
        {
            break; // No need to continue if the square of the prime is greater than n
        }
        removeMultiplesARR(primes, currentPrime);
    }
}

void generatePrimesLinkedList(LinkedList *primes, int n)
{
    // Add odd numbers up to n
    for (int i = 3; i <= n; i += 2)
    {
        addToLinkedList(primes, i);
    }

    // Apply the multiple method to remove non-prime numbers
    cell *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = current->value;
        if (currentPrime * currentPrime > n)
        {
            break; // No need to continue if the square of the prime is greater than n
        }
        removeMultiplesLL(primes, currentPrime);
        current = current->next;
    }
}

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
    destroyLinkedList(linkedListPrimes);

    return 0;
}