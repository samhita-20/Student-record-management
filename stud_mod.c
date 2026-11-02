#include "header.h"

void stud_mod(ST *ptr) {
    char op, ch, name[50];
    int roll, found = 0;
    float mark;
    ST *temp = ptr;

    if(ptr == NULL) {
        printf("No record in the list...\n");
        return;
    }

    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("\nEnter Your Choice: ");
    scanf(" %c", &op);

    if(op == 'R' || op == 'r') {
        printf("Enter the roll number: ");
        scanf("%d", &roll);

        while(temp != NULL) {
            if(temp->roll == roll) {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }
    else if(op == 'N' || op == 'n') {
        printf("Enter the name: ");
        scanf(" %49[^\n]", name);

        printf("\nRoll No\t\tName\t\tPercentage\n");

        while(temp != NULL) {
            if(strcmp(temp->name, name) == 0) {
                printf("%d\t\t%s\t\t%.2f\n",
                       temp->roll, temp->name, temp->mark);
            }

            temp = temp->next;
        }

        printf("Enter the roll number: ");
        scanf("%d", &roll);

        temp = ptr;

        while(temp != NULL) {
            if(temp->roll == roll) {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }
    else if(op == 'P' || op == 'p') {
        printf("Enter the percentage: ");
        scanf("%f", &mark);

        printf("\nRoll No\t\tName\t\tPercentage\n");

        while(temp != NULL) {
            if(temp->mark == mark) {
                printf("%d\t\t%s\t\t%.2f\n",
                       temp->roll, temp->name, temp->mark);
            }

            temp = temp->next;
        }

        printf("Enter the roll number: ");
        scanf("%d", &roll);

        temp = ptr;

        while(temp != NULL) {
            if(temp->roll == roll) {
                found = 1;
                break;
            }

            temp = temp->next;
        }
    }
    else {
        printf("Invalid choice...\n");
        return;
    }

    if(found == 0) {
        printf("No data found in the list...\n");
        return;
    }

    printf("\nN/n : Name\n");
    printf("P/p : Percentage\n");
    printf("\nEnter Your Choice: ");
    scanf(" %c", &ch);

    if(ch == 'N' || ch == 'n') {
        printf("Enter the new name: ");
        scanf(" %49[^\n]", temp->name);
    }
    else if(ch == 'P' || ch == 'p') {
        printf("Enter the new percentage: ");
        scanf("%f", &temp->mark);
    }
    else {
        printf("Invalid choice...\n");
        return;
    }

    printf("Record modified successfully...\n");
}
