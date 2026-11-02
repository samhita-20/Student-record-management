#include "header.h"

void stud_del(ST **ptr) {
    char op, name[50];
    int roll;
    ST *temp;

    if((*ptr) == NULL) {
        printf("No data...\n");
        return;
    }

    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("\nEnter Your Choice: ");
    scanf(" %c", &op);
    //to delete using roll number

    if(op == 'R' || op == 'r') {
        printf("Enter the roll number: ");
        scanf("%d", &roll);

    }
    //to delete using name
    else if(op == 'N' || op == 'n') {
        printf("Enter the name: ");
        scanf(" [^\n]", name);

        temp = (*ptr);

        printf("\nRoll No\t\tName\t\tPercentage\n");

        while(temp != NULL) {
            if(strcmp(temp->name, name) == 0) { //to check whether the details match with available details
                printf("%d\t\t%s\t\t%.2f\n",
                       temp->roll, temp->name, temp->mark);
            }

            temp = temp->next;//to move to next next node
        }

        printf("Enter the roll number to delete: ");
        scanf("%d", &roll);
    }
    //if roll no doesn't match
    else {
        printf("Invalid choice...\n");
        return;
    }
    //if they match

    temp = (*ptr);
    ST *prv = NULL;

    while(temp != NULL) {
        if(temp->roll == roll) {
            if(temp == (*ptr)) {
                (*ptr) = (*ptr)->next;
            }
            else {
                prv->next = temp->next;
            }

            free(temp);
            printf("Successfully deleted the record...\n");
            return;
        }
        else {
            prv = temp;
            temp = temp->next;
        }
    }

    printf("No data found in the list...\n");
}
