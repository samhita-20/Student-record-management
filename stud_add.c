#include "header.h"

void stud_add(ST **ptr) {
    ST *new = (ST *)malloc(sizeof(ST));//allocating new memory

    if(new == NULL) {
        printf("Memory allocation failed...\n");//if no memory was created
        return;
    }
//to generate roll.no automatically
    int roll = 1;
    ST *temp = (*ptr);

    while(temp != NULL) {
        if(temp->roll == roll) {
            roll++;//if a number is set,automatically it increases to second number
            temp = (*ptr);
        }
        else {
            temp = temp->next;
        }
    }
    new->roll = roll;

    printf("Enter the name: ");
    scanf(" %[^\n]", new->name);

    printf("Enter the percentage: ");
    scanf("%f", &new->mark);

    new->next = NULL;
    //for first node

    if((*ptr) == NULL) {
        (*ptr) = new;
    }
    //if not firt then add at end
    else {
        ST *last = (*ptr);

        while(last->next != NULL)
            last = last->next;

        last->next = new;
    }

    printf("Roll Number: %d\n", new->roll);
    printf("Node successfully linked..\n");
}
