#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st {
    int roll;
    char name[50];
    float mark;
    struct st *next;
} ST;

void stud_add(ST **);
void stud_del(ST **);
void stud_show(ST *);
void stud_mod(ST *);
void stud_save(ST *);
void stud_load(ST **);
void stud_sort(ST *);
void delete_all(ST **);
