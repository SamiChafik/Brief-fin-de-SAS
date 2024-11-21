#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day,month,year;
} date;
typedef struct {
    char title[100],discreptiona[400];
    int prio;
    date date;
} task;

void add() {
    printf ("test 1\n");
}
void show() {
    printf ("test 2\n");
}
void edit() {
    printf ("test 3\n");
}
void delete() {
    printf ("test 4\n");
}
void sort() {
    printf ("test 5\n");
}

int main() {
    int ch;

    do {
        printf ("=== Menu ===\n");
        printf ("1-Add new task\n");
        printf ("2-Show tasks\n");
        printf ("3-Edit a task\n");
        printf ("4-Delete a task\n");
        printf ("5-Sort tasks\n");
        printf ("0-Exit\n");

        printf (" ==> entre your choice : ");
        scanf ("%d", &ch);

        switch (ch) {
            case 0 :
            printf ("exiting program...");
            break;
            case 1 :
            add();
            break;
            case 2 :
            show();
            break;
            case 3 :
            edit();
            break;
            case 4 :
            delete();
            break;
            case 5 :
            sort();
            break;
            default : printf ("invalid choice, try again.\n");
        }
    } while (ch != 0);
}