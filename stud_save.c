#include "header.h"

void stud_save(ST *ptr) {
    FILE *fs = fopen("student.dat", "w");

    if(fs == NULL) {
        printf("Unable to open the file...\n");
        return;
    }

    while(ptr != NULL) {
        fprintf(fs, "%d %s %.2f\n",
                ptr->roll, ptr->name, ptr->mark);

        ptr = ptr->next;
    }

    fclose(fs);

    printf("Data stored successfully into file\n");
}

void stud_load(ST **ptr) {
    FILE *fs = fopen("student.dat", "r");
    int roll;
    char name[50];
    float mark;

    if(fs == NULL)
        return;

    while(fscanf(fs, "%d %49s %f",
        &roll, name, &mark) == 3) {

        ST *new = (ST *)malloc(sizeof(ST));

    if(new == NULL) {
        printf("Memory allocation failed...\n");
        fclose(fs);
        return;
    }

    new->roll = roll;
    strcpy(new->name, name);
    new->mark = mark;
    new->next = NULL;

    if((*ptr) == NULL) {
        (*ptr) = new;
    }
    else {
        ST *last = (*ptr);

        while(last->next != NULL)
            last = last->next;

        last->next = new;
    }
        }

        fclose(fs);
}

void delete_all(ST **ptr) {
    while((*ptr) != NULL) {
        ST *temp = (*ptr);

        (*ptr) = (*ptr)->next;

        free(temp);
    }
}
