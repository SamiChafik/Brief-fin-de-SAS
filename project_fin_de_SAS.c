#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day,month,year;
} date;
typedef struct {
    char title[100],description[400];
    int prio;
    int completion;
    date date;
} task;

int count = 0;

void add(task t[]) {
    int ch;
    if (count >= 1) {
        printf ("\nyou reached the limit of tasks you can add.\n");
        return; 
    }

    while (1) {
        do {
            printf ("\n1-Creat new task\n2-Return to main menu\n=> ");
            scanf ("%d", &ch);

            if (ch == 1) {
                printf ("\n=== Task %d ===\n", count+1);
                printf ("title : ");
                scanf (" %[^\n]", t[count].title);
                printf ("description : ");
                scanf (" %[^\n]", t[count].description);

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
            } else printf ("\ninvalid choice, try again !\n");
        } while (ch < 1 || ch > 2);
    }
}

void show(task t[]) {
    int i,ch;
    int d = 0;

    if (count == 0) { 
        printf ("\n<= no tasks stored ! =>\n");
        return;
    }

    if (count == 1) {
        printf ("\nThere is one task\n");
    } else printf ("\nThere are %d tasks\n", count);
    
    while (1) {
        printf ("\n1-Show all tasks\n2-Show high priority tasks\n3-Show low priority tasks\n4-Return to main menu\n=> ");
        scanf ("%d", &ch);

        for (i = 0; i < count; i++) {
            if ((ch == 2 && t[i].prio != 1 ) || (ch == 3 && t[i].prio != 2)) {
                continue;
            }
            
            printf ("\n=== Task %d ===\n", i+1);
            printf ("Title : %s\n", t[i].title);
            printf ("Description : %s\n", t[i].description);
            printf ("Priority : ");
            if (t[i].prio == 1) {
            printf ("High\n");
            } else printf ("low\n");
            printf ("The deadline date for this task is : %d / %d / %d \n", t[i].date.day, t[i].date.month, t[i].date.year);

            printf ("=========\n");
                
            d = 1;
            
        }

        if (d == 0) {
            printf ("\nNo task with this priority was found !\n");
        }

        if (ch == 4) {
            return;
        }
    }
}

void edit(task t[]) {
    int num,ch,ch2,ch3;

    if (count == 0) { 
        printf ("\n<= No tasks stored ! =>\n");
        return;
    }

    while (1) {
        do {
            printf ("\n1-Edit existing task\n2-Return to main menu\n=> ");
            scanf ("%d", &ch);

            if (ch == 1) {

                printf ("Enter the task number you want to edit (1 - %d) : ", count);
                scanf ("%d", &num);

                if (num < 0 || num > count) {
                        printf ("\nTask does not exist !\n");
                        break;
                    }
                
                printf ("\n1-Edit all\n2-Edit title\n3-Edit discription\n4-Edit priority\n5-Edit date\n6-Return\n=> ");
                scanf ("%d", &ch2);
                switch (ch2) {
                    
                    case 1 :

                    num--;

                    printf ("\n=== Task %d ===\n", num+1);
                    printf ("New tilte : ");
                    scanf (" %[^\n]", t[num].title);
                    printf ("New description : ");
                    scanf (" %[^\n]", t[num].description);

                    do {
                        printf ("Priority\n1-high\n2-low\nchoose one : ");
                        scanf ("%d", &t[count].prio);
                    } while (t[count].prio != 1 && t[count].prio != 2);

                    printf ("Enter new deadline date\n");

                    do {
                        printf ("day (1-31) : ");
                        scanf ("%d", &t[num].date.day);
                        if (t[num].date.day < 1 || t[num].date.day > 31) {
                            printf ("The day most be between 1 and 31\n");
                        }
                    } while (t[num].date.day < 1 || t[num].date.day > 31);

                    do {
                        printf ("month (1-12) : ");
                        scanf ("%d", &t[num].date.month);
                        if (t[num].date.month < 1 || t[num].date.month > 12) {
                            printf ("The month most be between 1 and 12\n");
                        }
                    } while (t[num].date.month < 1 || t[num].date.month > 12);

                    do {
                        printf ("year (2024 or above) : ");
                        scanf ("%d", &t[num].date.year);

                        if (t[num].date.year < 2024) {
                            printf ("The year most be 2024 or above\n");
                        }
                    } while (t[num].date.year < 2024 );

                    printf ("\n<= Task changed successfully ! =>\n");
                    break;

                    case 2 :

                    num--;

                    printf ("\n=== Task %d ===\n", num+1);
                    printf ("New tilte : ");
                    scanf (" %[^\n]", t[num].title);
                    break;

                    case 3 :
                    
                    num--;

                    printf ("\n=== Task %d ===\n", num+1);
                    printf ("New discription : ");
                    scanf (" %[^\n]", t[num].description);
                    break;

                    case 4 :
                    
                    num--;

                    printf ("\n=== Task %d ===\n", num+1);
                    do {
                        printf ("priority\n1-high\n2-low\nchoose one : ");
                        scanf ("%d", &t[num].prio);
                    } while (t[num].prio != 1 && t[num].prio != 2);
                    break;

                    case 5 :
                    printf ("\nEdit dead line date\n1-day\n2-month\n3-year\n4-Return\n=> ");
                    scanf ("%d", &ch3);
                    switch (ch3) {

                        case 1 :
                        
                        num--;

                        printf ("\n=== Task %d ===\n", num+1);

                        do {
                        printf ("day (1-31) : ");
                        scanf ("%d", &t[num].date.day);

                            if (t[num].date.day < 1 || t[num].date.day > 31) {
                                printf ("day most be between 1 and 31\n");
                            }
                        } while (t[num].date.day < 1 || t[num].date.day > 31);
                        break;

                        case 2 :                      

                        num--;

                        printf ("\n=== Task %d ===\n", num+1);
                        do {
                        printf ("month (1-12) : ");
                        scanf ("%d", &t[num].date.month);
                        if (t[num].date.month < 1 || t[num].date.month > 12) {
                            printf ("month most be between 1 and 12\n");
                        }
                        } while (t[num].date.month < 1 || t[num].date.month > 12);
                        break;

                        case 3 :
                        
                        num--;

                        printf ("\n=== Task %d ===\n", num+1);
                        do {
                        printf ("year (2024 or above) : ");
                        scanf ("%d", &t[num].date.year);

                        if (t[num].date.year < 2024) {
                            printf ("the year most be 2024 or above\n");
                        }
                        } while (t[num].date.year < 2024 );
                        break;

                        case 4 :
                        break;
                    }
                    case 6 :
                    break;
                }
            } else if (ch == 2) {
                return;
            } else printf ("\ninvalid choice, try again !\n");
        } while (ch < 1 || ch > 2);
    }
}

void delete(task t[]) {
    int ch,i,num;
    
    if (count == 0) { 
        printf ("\n<= no tasks stored ! =>\n");
        return;
    }

    while (1) {
        do {
            printf ("\n1-Delete one task\n2-Delete all tasks\n3-Return to main menu\n=> ");
            scanf ("%d", &ch);

            if (ch == 1) {
                printf ("\nEntre the task number you want to delete (1 - %d) : ", count);
                scanf ("%d", &num);
                
                if (num > count) {
                printf ("\nthis task does not exist !\n");
                continue;
                }
                num--;

                for (i=num; i < count; i++) {
                    t[i] = t[i+1];
                }

                printf ("\n<= task deleted successfuly ! =>\n");

                count--;
            } else if (ch == 2) {
                count = 0;
                printf ("\n<= All tasks deleted succefully ! =>\n");
            } else if (ch == 3) {
                return;
            } else printf ("\ninvalid choice, try again !\n");
        } while (ch < 1 || ch > 3);
    }
}

void sort() {
    printf ("work in progress...\n");
}

int main() {
    int ch;
    task t[50];

    do {
        printf ("\n=== Menu ===\n1-Add a new task\n2-Show tasks\n3-Edit a task\n4-Delete a task\n5-Sort tasks\n0-Exit\n");

        printf (" ==> entre your choice : ");
        scanf ("%d", &ch);

        switch (ch) {
            case 0 : printf ("exiting program...");
            break;
            case 1 : add(t);           
            break;
            case 2 : show(t);
            break;
            case 3 : edit(t);          
            break;
            case 4 : delete(t);          
            break;
            case 5 : sort();           
            break;
            default : printf ("\ninvalid choice, try again.\n");
        }
    } while (ch != 0);
}