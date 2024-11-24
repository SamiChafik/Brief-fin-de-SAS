#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day,month,year;
} date;
typedef struct {
    char title[100],discreption[400];
    int prio;
    date date;
} task;

int count = 0;

void add(task t[]) {
    int ch;
    if (count >= 50) {
        printf ("you reach the limit of tasks you can add.\n");
        return; 
    }

    while (1) {
        do {
            printf ("1-Creat new task\n2-Return to main menut\n=> ");
            scanf ("%d", &ch);

            if (ch == 1) {
                printf ("=== Task %d ===\n", count+1);
                printf ("title : ");
                scanf (" %[^\n]", t[count].title);
                printf ("discription : ");
                scanf (" %[^\n]", t[count].discreption);

                do {
                    printf ("priority\n1-high\n2-low\nchoose one : ");
                    scanf ("%d", &t[count].prio);
                } while (t[count].prio != 1 && t[count].prio != 2);

                printf ("Enter the deadline date\n");
                do {
                    printf ("day (1-31) : ");
                    scanf ("%d", &t[count].date.day);
                    if (t[count].date.day < 1 || t[count].date.day > 31) {
                        printf ("day most be between 1 and 31\n");
                    }
                } while (t[count].date.day < 1 || t[count].date.day > 31);

                do {
                    printf ("month (1-12) : ");
                    scanf ("%d", &t[count].date.month);
                    if (t[count].date.month < 1 || t[count].date.month > 12) {
                        printf ("month most be between 1 and 12\n");
                    }
                } while (t[count].date.month < 1 || t[count].date.month > 12);

                do {
                    printf ("year (2024 or above) : ");
                    scanf ("%d", &t[count].date.year);
                    if (t[count].date.year < 2024) {
                        printf ("the year most be 2024 or above\n");
                    }
                } while (t[count].date.year < 2024 );

                count++;

                printf ("=== Task added ! ===\n");
            } else if (ch == 2) {
                return;
            } else printf ("invalid choice, try again !\n");
        } while (ch < 1 || ch > 2);
    }
}
void show(task t[]) {
    int i,ch;
    printf ("1-Show all tasks\n2-Show high priority tasks\n3-Show low priority tasks\n4-Return to main menu\n=> ");
    scanf ("%d", &ch);

    if (ch == 1) {
        if (count == 0) { 
            printf ("<= no tasks stored ! =>\n");

        
        } else {
            for (i = 0; i < count; i++) {
                printf ("<= List of tasks =>\n");
                printf ("=== Task %d ===\n", i+1);
                printf ("Tilte : %s\n", t[i].title);
                printf ("description : %s\n", t[i].discreption);
                printf ("prio : ");
                if (t[i].prio == 1) {
                    printf ("high\n");
                } else printf ("low\n");
                printf ("the deadline date for this task is : %d / %d / %d \n", t[i].date.day, t[i].date.month, t[i].date.year);
            }
        }
    } else if (ch == 4) {
        return;
    }
}
void edit(task t[]) {
    int num,ch;
    while (1) {
        do {
            printf ("1-Edit existing task\n2-Return to main menu\n=> ");
            scanf ("%d", &ch);

            if (ch == 1) {
                printf ("enter the task number you want to edit : ");
                scanf ("%d", &num);

                if (num < 0 || num > count) {
                    printf ("task does not exist !\n");
                    return;
                }

                num--;

                printf ("=== Task %d ===\n", num+1);
                printf ("New tilte : ");
                scanf (" %[^\n]", t[num].title);
                printf ("New description : ");
                scanf (" %[^\n]", t[num].discreption);

                do {
                    printf ("priority\n1-high\n2-low\nchoose one : ");
                    scanf ("%d", &t[count].prio);
                } while (t[count].prio != 1 && t[count].prio != 2);

                printf ("Enter new deadline date\n");

                do {
                    printf ("day (1-31) : ");
                    scanf ("%d", &t[num].date.day);
                    if (t[num].date.day < 1 || t[num].date.day > 31) {
                        printf ("day most be between 1 and 31\n");
                    }
                } while (t[num].date.day < 1 || t[num].date.day > 31);

                do {
                    printf ("month (1-12) : ");
                    scanf ("%d", &t[num].date.month);
                    if (t[num].date.month < 1 || t[num].date.month > 12) {
                        printf ("month most be between 1 and 12\n");
                    }
                } while (t[num].date.month < 1 || t[num].date.month > 12);

                do {
                    printf ("year (2024 or above) : ");
                    scanf ("%d", &t[num].date.year);

                    if (t[num].date.year < 2024) {
                        printf ("the year most be 2024 or above\n");
                    }
                } while (t[num].date.year < 2024 );

                printf ("<= Task changed successfully ! =>\n");
            } else if (ch == 2) {
                return;
            } else printf ("invalid choice, try again !\n");
        } while (ch < 1 || ch > 2);
    }
}
void delete(task t[]) {
    int ch,i,num;

    while (1) {
        do {
            printf ("1-Delete one tastk\n2-Delete all tasks\n3-Return to main menu\n=> ");
            scanf ("%d", &ch);

            if (ch == 1) {
                printf ("entre the task number you want to delete : ");
                scanf ("%d", &num);
                
                if (num > count) {
                printf ("this task does not exist !\n");
                return;
                }
                num--;

                for (i=num; i < count; i++) {
                    t[i] = t[i+1];
                }

                printf ("\n<= task deleted successfuly ! =>\n");

                count--;
            } else if (ch == 2) {
                count = 0;
                printf ("<= all tasks deleted succefully ! =>\n");
            } else if (ch == 3) {
                return;
            } else printf ("invalid choice, try again !\n");
        } while (ch < 1 || ch > 3);
    }
}
void sort() {
    printf ("test 5\n");
}

int main() {
    int ch;
    task t[50];

    do {
        printf ("=== Menu ===\n1-Add a new task\n2-Show tasks\n3-Edit a task\n4-Delete a task\n5-Sort tasks\n0-Exit\n");

        printf (" ==> entre your choice : ");
        scanf ("%d", &ch);

        switch (ch) {
            case 0 :
            printf ("exiting program...");
            break;
            case 1 :
            add(t);
            break;
            case 2 :
            show(t);
            break;
            case 3 :
            edit(t);
            break;
            case 4 :
            delete(t);
            break;
            case 5 :
            sort();
            break;
            default : printf ("invalid choice, try again.\n");
        }
    } while (ch != 0);
}