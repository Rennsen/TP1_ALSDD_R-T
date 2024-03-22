#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Cell structure for linked list
typedef struct Cell
{
    int value;
    bool deleted;
    struct Cell *next;
} Cell;

// Structures
typedef struct DynamicArray
{
    int *array;
    bool *deleted;
    size_t size;
    size_t capacity;
} DynamicArray;

// Pointer to cell structure in the library
typedef struct LinkedList
{
    Cell *head;
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
    arr->deleted = (bool *)malloc(initialCapacity * sizeof(bool));
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

void destroyDynamicArray(DynamicArray *arr)
{
    free(arr->array);
    free(arr->deleted);
    free(arr);
}

void addToDynamicArray(DynamicArray *arr, int element)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
        arr->deleted = (bool *)realloc(arr->deleted, arr->capacity * sizeof(bool));
    }
    arr->array[arr->size] = element;
    arr->deleted[arr->size] = false;
    arr->size++;
}

void removeMultiplesARR(DynamicArray *arr, int multiple)
{
    for (size_t i = 0; i < arr->size; ++i)
    {
        if (!arr->deleted[i] && arr->array[i] % multiple == 0 && arr->array[i] != multiple)
        {
            arr->deleted[i] = true;
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
    Cell *current = list->head;
    Cell *next;
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
    Cell *newCell = (Cell *)malloc(sizeof(Cell));
    newCell->value = element;
    newCell->deleted = false;
    newCell->next = NULL;
    // If the list is empty, we set the newcell to head
    if (list->head == NULL)
    {
        list->head = newCell;
    }
    else
    {
        // Go through list to find the last element
        Cell *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Append newcell to the last element
        current->next = newCell;
    }
    list->size++;
}

void removeMultiplesLL(LinkedList *list, int multiple)
{
    Cell *current = list->head;
    while (current != NULL)
    {
        if (!current->deleted && current->value % multiple == 0 && current->value != multiple)
        {
            current->deleted = true;
        }
        current = current->next;
    }
}

// Prime Generation
void generatePrimesDynamicArray(DynamicArray *primes, int n)
{
    for (int i = 3; i <= n; i += 2)
    {
        addToDynamicArray(primes, i);
    }

    for (size_t i = 0; i < primes->size; ++i)
    {
        int currentPrime = primes->array[i];
        if (currentPrime * currentPrime > n)
        {
            break;
        }
        removeMultiplesARR(primes, currentPrime);
    }
}

void generatePrimesLinkedList(LinkedList *primes, int n)
{
    for (int i = 3; i <= n; i += 2)
    {
        addToLinkedList(primes, i);
    }

    Cell *current = primes->head;
    while (current != NULL)
    {
        int currentPrime = current->value;
        if (currentPrime * currentPrime > n)
        {
            break;
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
        if (!dynamicPrimes->deleted[i])
        {
            printf("%d ", dynamicPrimes->array[i]);
        }
    }
    printf("\n");
    destroyDynamicArray(dynamicPrimes);

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);
    printf("Primes using Linked List: 2 ");
    Cell *current = linkedListPrimes->head;
    while (current != NULL)
    {
        if (!current->deleted)
        {
            printf("%d ", current->value);
        }
        current = current->next;
    }
    printf("\n");

    destroyLinkedList(linkedListPrimes);
    return 0;
}
