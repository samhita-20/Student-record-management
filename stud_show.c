#include "header.h"

void stud_show(ST *ptr) {
    if(ptr == NULL) {
        printf("No record in the list...\n");
        return;
    }

    printf("\n-----------------------------------------------\n");
    printf("%-10s %-22s %-12s\n",
           "Roll No", "Name", "Percentage");
    printf("-----------------------------------------------\n");

    while(ptr != NULL) {
        printf("%-10d %-22s %-12.2f\n",
               ptr->roll, ptr->name, ptr->mark);

        ptr = ptr->next;
    }

    printf("-----------------------------------------------\n");
}
