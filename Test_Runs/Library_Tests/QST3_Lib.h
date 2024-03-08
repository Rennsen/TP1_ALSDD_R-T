#ifndef QST3LIB_H
#define QST3LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AbstractMachineSingly.h"
#include "QST2_Lib.h"

int find_max(cell * head);
int find_min(cell * head);
void IndexListByRange(LinkedList *LinkedListPrimes);

int find_min(cell * head){
    cell * temp = head;
    if(head==NULL){
        printf("the list is empty");
    }else{
    int min=2;
    while(temp!=NULL){
        if(min>=value(temp)){
            min=value(temp);
        }
        temp=next(temp);
    }
    return min;
    }
}
int find_max(cell * head){
    cell * temp = head;
    if(head==NULL){
        printf("the list is empty");
    }else{
    int max=head->value;
    while(temp!=NULL){
        if(max<value(temp)){
            max=value(temp);
        }
        temp=next(temp);
    }
    return max;
    }
}


// indexing the list by range for printing prime numbers between two values
void IndexListByRange(LinkedList *LinkedListPrimes){
    cell *temp1 = LinkedListPrimes->head;
    cell *head2;

    int max, min;
    bool inrange = true;


    printf("%d\n",find_max(temp1));
    printf("%d\n",find_min(temp1));
    do{
        printf("the max bound : ");
        scanf("%d", &max);
        printf("the min bound : ");
        scanf("%d", &min);
            if(max > find_max(temp1) || min < find_min(temp1) || (min > max)){
                printf("Invalid Range. Please reselect accordingly.\n");
                inrange = false;
            }
    }while((!inrange) || (max < min));

    if(min == 2){
        printf("2 | ");
    }

    while (temp1->next != NULL)
    {
        if (temp1->value >= min)
        {
            head2 = temp1;
            break;
        }
        temp1 = temp1->next;
    }

    cell *temp2 = temp1;
    while (temp2 != NULL)
    {
        if (temp2->value > max)
        {
            break;
        }
        temp2 = temp2->next;
    }
    temp1 = head2;
    while (temp1 != temp2)
    {
        printf("%d | ", temp1->value);
        temp1 = temp1->next;
    }
}

#endif