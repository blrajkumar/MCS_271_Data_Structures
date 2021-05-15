/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : Test 04
 * ********************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define NAME_SIZE 50

void insert();
void del();
void display();
void displaymax();
void addpublc();
void srchemp();

struct node
{
    int noOfPublc;
    int empid;
    char name[NAME_SIZE];
    struct node *next;
} *start = NULL, *q, *temp, *new;

typedef struct node N;
int main()
{
    int ch;
    printf("\n*************************\n*  Name : Rajkumar B L  *\n*  Reg  : 2047120       *\n*  Lab  : Test 04       *\n*************************\n");

    do
    {
        printf("\n=========================\n\tMenu\n=========================\n");
        printf("1. Insert Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Display Max Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Add Publication\n");
        printf("6. Search Employee\n");
        printf("7. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            displaymax();
            break;
        case 4:
            display();
            break;
        case 5:
            addpublc();
            break;
        case 6:
            srchemp();
            break;
        case 7:
            printf("Bye!\n\n");
            exit(0);
        default:
            printf("Invalid Input!\n");
        }
    } while (ch != 7);
}

void insert()
{
    int item, itprio;
    char itname[50];
    new = (N *)malloc(sizeof(N));
    printf("Enter the Employee Id : ");
    scanf("%d", &item);
    printf("Enter the name : ");
    fflush(stdin);
    scanf("%s", new->name);
    printf("Enter no of publications : ");
    scanf("%d", &itprio);
    new->empid = item;
    new->noOfPublc = itprio;
    new->next = NULL;
    if (start == NULL)
    {
        //new->next=start;
        start = new;
    }
    else if (start != NULL && itprio <= start->noOfPublc)
    {
        new->next = start;
        start = new;
    }
    else
    {
        q = start;
        while (q->next != NULL && q->next->noOfPublc <= itprio)
        {
            q = q->next;
        }
        new->next = q->next;
        q->next = new;
    }

    printf("Empoloyee added successfully\n");
}

void del()
{
    if (start == NULL)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        new = start;
        printf("\nDeleted Employee Id is %d\n", new->empid);
        start = start->next;
        //free(start);
    }
}

void display()
{
    temp = start;
    if (start == NULL)
        printf("Queue is empty\n");
    else
    {
        
        if (temp != NULL)
            printf("\n-------------------------\n  The Employee Queue\n-------------------------\n");
            for (temp = start; temp != NULL; temp = temp->next)
            {
                printf("\nEmployee Id : %d \nEmployee Name : %s\nNo of Publications : %d\n", temp->empid,temp->name,temp->noOfPublc);
            }
            printf("\n-------------------------\n");
    }
}

void displaymax()
{
    int maxempid = 0;
    int maxpubl = 0;
    temp = start;
    char higname[NAME_SIZE];
    if (start == NULL)
        printf("Queue is empty\n");
    else
    {
        
        if (temp != NULL)
        {
            printf("\n-------------------------\n Employee with max publc\n-------------------------\n");
            temp = start;
            maxempid = temp->empid;
            maxpubl = temp->noOfPublc;
            for (temp = start; temp != NULL; temp = temp->next)
            {
                if (maxpubl <= temp->noOfPublc)
                {
                    maxempid = temp->empid;
                    maxpubl = temp->noOfPublc;
                    strcpy(higname, temp->name);
                }
            }

            printf("\nEmployee Id : %d \nEmployee Name : %s\nNo of Publications : %d\n", maxempid, higname, maxpubl);
            printf("\n-------------------------\n");
        }
           
    }
}

void srchemp()
{
    int maxempid = 0;
    int maxpubl = 0;
    temp = start;
    if (start == NULL)
        printf("Queue is empty\n");
    else
    {

        int item, itprio, fnd, temppublc;
        fnd = 0; temppublc = 0;
        printf("Enter the Employee Id : ");
        scanf("%d", &item);

        for (temp = start; temp != NULL; temp = temp->next)
        {
            if (item == temp->empid)
            {
                fnd = 1;
                temppublc = temp->noOfPublc;
            }
        }

        if (fnd < 1)
        {
            printf("Employee Id not Found!\nPlease try again.\n");
        }
        else
        {
            printf("Employee %d exits\nNo of Publications : %d\n", item, temppublc);
        }
    }
}

void addpublc()
{
    temp = start;
    if (start == NULL)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        int item, itprio, fnd;
        fnd=0;
        printf("Enter the Employee Id : ");
        scanf("%d", &item);
       
        for (temp = start; temp != NULL; temp = temp->next)
        {
            if (item == temp->empid)
            {
                fnd=1;
                printf("Enter no of publications to add : ");
                scanf("%d", &itprio);
                temp->noOfPublc = temp->noOfPublc + itprio;
            }
        }

        if(fnd<1)
        {
            printf("Employee Id not Found!\nPlease try again.\n");
        }
        else
        {
            printf("Publications added successfully\n");
        }
    }
}
