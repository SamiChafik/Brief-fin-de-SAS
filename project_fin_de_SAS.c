#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int hour,day,month;
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
    printf ("priority\n1-high\n2-low)\nchoose one : ");
    scanf ("%d", &t[count].prio);
    count++;
    printf ("=== Task added ! ===\n");
}
void show(task t[]) {
    int i;
    printf ("<= List of tasks =>\n");

    for (i = 0; i < count; i++) {
        printf ("=== Task %d ===\n", i+1);
        printf ("Tilte : %s\n", t[i].title);
        printf ("description : %s\n", t[i].discreption);
        printf ("prio : ");
        if (t[i].prio == 1) {
            printf ("high\n");
        } else printf ("low\n");
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
    printf ("Change priority (1-high or 2-low) : ");
    scanf ("%d", &t[num].prio);
    printf ("<= Task changed successfully ! =>\n");
}
void delete() {
    printf ("test 4\n");
}
void sort() {
    printf ("test 5\n");
}

int main() {
    int ch;
    task t[50];

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
            add(t);
            break;
            case 2 :
            show(t);
            break;
            case 3 :
            edit(t);
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