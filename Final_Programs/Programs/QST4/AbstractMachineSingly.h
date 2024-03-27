#ifndef AbstrMachSingly_H
#define AbstrMachSingly_H

#include <stdlib.h>
#include <stdio.h>


typedef struct LinkedList LinkedList;

typedef struct cell
{
    int value;
    bool deleted;
    struct cell *next;
    LinkedList *sublist;
} cell;


void allocate_cell(cell **p);
void free_cell(cell *head);
int value(cell *p);
cell *next(cell *p);
void ass_val(cell *p, int v);
void ass_adr(cell *p, cell *q);

// abstract machine implementation

void allocate_cell(cell **p)
{ // allocate a cell
    *p = (cell *)malloc(sizeof(cell));
}

void free_cell(cell *head)
{ // free all the cells of the list
    while (head != NULL)
    {
        cell *p = head;
        head = head->next;
        free(p);
    }
}

int value(cell *p)
{ // give the value of a cell
    if (p != NULL)
    {
        return p->value;
    }
    else
    {
        // Handle NULL pointer case, return an error value.
        perror("Error.");
        return -1;
    }
}

cell *next(cell *p)
{ // give the next cell pointer
    if (p != NULL)
    {
        return p->next;
    }
    else
    {
        // Handle NULL pointer case, return NULL.
        perror("Error.");
        return NULL;
    }
}

void ass_val(cell *p, int v)
{ // assign a value to the cell
    if (p != NULL)
    {
        p->value = v;
    }
}

void ass_adr(cell *p, cell *q)
{ // assign a next value to the cell
    if (p != NULL)
    {
        p->next = q;
    }
}

#endif