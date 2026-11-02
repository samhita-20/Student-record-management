#include "header.h"

void stud_sort(ST *ptr) {
    char op;
    ST *temp, *last;
    int roll;
    char name[50];
    float mark;

    if(ptr == NULL) {
        printf("No record in the list...\n");
        return;
    }

    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("\nEnter Your Choice: ");
    scanf(" %c", &op);

    if(op == 'N' || op == 'n') {
        for(temp = ptr; temp->next != NULL;
            temp = temp->next) {

            for(last = temp->next; last != NULL;
                last = last->next) {

                if(strcmp(temp->name, last->name) > 0) {
                    roll = temp->roll;
                    temp->roll = last->roll;
                    last->roll = roll;

                    strcpy(name, temp->name);
                    strcpy(temp->name, last->name);
                    strcpy(last->name, name);

                    mark = temp->mark;
                    temp->mark = last->mark;
                    last->mark = mark;
                }
                }
            }
    }
    else if(op == 'P' || op == 'p') {
        for(temp = ptr; temp->next != NULL;
            temp = temp->next) {

            for(last = temp->next; last != NULL;
                last = last->next) {

                if(temp->mark > last->mark) {
                    roll = temp->roll;
                    temp->roll = last->roll;
                    last->roll = roll;

                    strcpy(name, temp->name);
                    strcpy(temp->name, last->name);
                    strcpy(last->name, name);

                    mark = temp->mark;
                    temp->mark = last->mark;
                    last->mark = mark;
                }
                }
            }
    }
    else {
        printf("Invalid choice...\n");
        return;
    }

    printf("List sorted successfully...\n");
}
