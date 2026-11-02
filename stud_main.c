#include "header.h"

int main() {
    ST *hptr = NULL;
    char op, ch;

    stud_load(&hptr);

    do {
        printf("\n**** STUDENT RECORD MENU ****\n\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("\nEnter Your Choice: ");
        scanf(" %c", &op);

        switch(op) {
            case 'A':
            case 'a':
                stud_add(&hptr);
                break;

            case 'D':
            case 'd':
                stud_del(&hptr);
                break;

            case 'S':
            case 's':
                stud_show(hptr);
                break;

            case 'M':
            case 'm':
                stud_mod(hptr);
                break;

            case 'V':
            case 'v':
                stud_save(hptr);
                break;

            case 'T':
            case 't':
                stud_sort(hptr);
                break;

            case 'E':
            case 'e':
                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("\nEnter Your Choice: ");
                scanf(" %c", &ch);
                //if exit with saving

                if(ch == 'S' || ch == 's') {
                    stud_save(hptr);
                    delete_all(&hptr);
                    return 0;
                }
                //if exit without saving
                else if(ch == 'E' || ch == 'e') {
                    delete_all(&hptr);
                    return 0;
                }
                break;

            default:
                printf("Invalid choice...\n");
        }

    } while(1);

    return 0;
}
