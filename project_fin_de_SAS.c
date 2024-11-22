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
    if (count >= 50) {
        printf ("you reach the limit of tasks you can add.\n");
        return; 
    }
    
    printf ("=== Task %d ===\n", count+1);
    printf ("title : ");
    scanf (" %[^\n]", t[count].title);
    printf ("discription : ");
    scanf (" %[^\n]", t[count].discreption);
    do {
        printf ("priority\n1-high\n2-low\nchoose one : ");
        scanf ("%d", &t[count].prio);
    } while (t[count].prio != 1 && t[count].prio != 2);
    count++;
    printf ("=== Task added ! ===\n");
}
void show(task t[]) {
    int i;

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
        }
    }

}
void edit(task t[]) {
    int num;
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
    printf ("<= Task changed successfully ! =>\n");
}
void delete(task t[]) {
    int ch,i,num;
    printf ("1-delete one tastk\n2-delete all tasks\n");
    scanf ("%d", &ch);
    if (ch == 0 || ch > count) {
        printf ("this task does not exist !\n");
    }
    if (ch == 1) {
        printf ("entre the task number you want to delete : ");
        scanf ("%d", &num);
        num--;
        for (i=num; i < count; i++) {
            t[i] = t[i+1];
        }
        printf ("\n<= task deleted successfuly ! =>\n");
        count--;
    } else if (ch == 2) {
        count = 0;
        printf ("<= all tasks deleted succefully ! =>\n")
    } else printf ("invalid choice, try again !\n");
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