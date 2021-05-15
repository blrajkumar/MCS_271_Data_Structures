#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_SIZE 10

struct process
{
    int pid;
    char pstatus[STATUS_SIZE];
    int pvalue;
    struct process *next;
    struct process *prev;
};

struct process *head = NULL;

void addProcess()
{
    struct process *new_node;
    struct process *temp;
    temp = head;

    new_node = (struct process *)malloc(sizeof(struct process));
    printf("Process ID: ");
    fflush(stdin);
    scanf("%d", &new_node->pid);
    printf("Status: ");
    fflush(stdin);
    scanf("%s", new_node->pstatus);
    printf("Priority: ");
    fflush(stdin);
    scanf("%d", &new_node->pvalue);

    if (head == NULL)
    {
        head = new_node;
        new_node->prev = head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("Process Inserted!\n");
}

void deleteProcess()
{
    struct process *temp, *previous;
    temp = head;
    previous = head;
    int flag = 0;

    int del_pid;
    fflush(stdin);
    printf("Enter process id to be deleted: ");
    scanf("%d", &del_pid);

    if (temp == NULL)
        printf("The PCB is empty");
    else
    {
        while (temp != NULL)
        {
            if (temp->pid == del_pid)
            {
                if (temp != head)
                {
                    previous->next = temp->next;
                    temp = temp->next;
                    temp->prev = previous;
                }
                else
                {
                    head = temp->next;
                }
                printf("Process deleted.\n");
                flag = 1;
            }
            previous = temp;
            temp = temp->next;
        }
        if (flag == 0)
        {
            printf("Process not found!\n");
        }
    }
}

void displayAllProcess()
{
    struct process *temp;
    temp = head;
    int count = 1;

    if (temp == NULL)
        printf("The PCB is empty");
    else
    {
        printf("\n");
        while (temp != NULL)
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Process No : %d\n",count);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Process ID: %d\n", temp->pid);
            printf("Status: %s\n", temp->pstatus);
            printf("Priority: %d\n", temp->pvalue);
            temp = temp->next;
            count++;
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

void displayReadyProcesses()
{
    struct process *temp;
    int count = 0;
    temp = head;

    if (temp == NULL)
        printf("The PCB is empty");
    else
    {
        printf("\n=========================\n");
        printf("    All Ready Process   \n");
        printf("=========================\n");

        while (temp != NULL)
        {
            if (strcasecmp(temp->pstatus, "ready") == 0)
            {
                printf("=========================\n");
                printf("Process ID: %d\n", temp->pid);
                printf("Status: %s\n", temp->pstatus);
                printf("Priority: %d\n", temp->pvalue);
                count++;
            }
            temp = temp->next;
        }
        printf("=========================\n");
        printf("Total %d Ready Process.\n", count);
        printf("=========================\n");
    }
   
}

void displayPriorityProcess()
{
    struct process *temp;
    int high_pid = 0;
    int high_pvalue = 0;
    char high_status[20];
    int count  = 0;
    temp = head;

    while (temp != NULL)
    {
        if (count ==  0)
        {
            high_pid = temp->pid;
            high_pvalue = temp->pvalue;
            strcpy(high_status, temp->pstatus);
            count++;
        }
        else
        {
            if (temp->pvalue < high_pvalue)
            {
                high_pid = temp->pid;
                high_pvalue = temp->pvalue;
                strcpy(high_status, temp->pstatus);
            }
        }
        temp = temp->next;
    }
    if(count > 0)
    {
        printf("\n=========================\n");
        printf("  High Priority Process  \n");
        printf("=========================\n");
        printf("Process ID: %d\n", high_pid);
        printf("Status: %s\n", high_status);
        printf("Priority: %d\n", high_pvalue);
        printf("=========================");
    }
    else
    {
        printf("The PCB is empty");
    }
   
   

}

int main(int argc, char const *argv[])
{
    
    printf("\nProcess Control Block (PCB)!!!");
    int ch;

    do
    {
        printf("\n=========================\n\tMenu\n=========================\n");
        printf("1. Add Process\n");
        printf("2. Delete Process\n");
        printf("3. All Users\n");
        printf("4. Ready Process\n");
        printf("5. High Priority Process\n");
        printf("6. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addProcess();
            break;
        case 2:
            deleteProcess();
            break;
        case 3:
            displayAllProcess();
            break;
        case 4:
            displayReadyProcesses();
            break;
        case 5:
              displayPriorityProcess();
            break;
        case 6:
            printf("Bye.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("\n");
    } while (ch != 6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define ROLLNO_SIZE 10
#define MARK_SIZE 10

struct member
{
    char name[NAME_SIZE];
    char rollNo[ROLLNO_SIZE];
    char mark[MARK_SIZE];
    struct member *next;
};

struct member *head = NULL;

void addStudent()
{
    struct member *new_node;
    struct member *temp;
    temp = head;

    new_node = (struct member *)malloc(sizeof(struct member));
    printf("Enter Name: ");
    fflush(stdin);
    scanf("%s", new_node->name);
    printf("Enter RollNo: ");
    fflush(stdin);
    scanf("%s", new_node->rollNo);
    printf("Enter Mark: ");
    fflush(stdin);
    scanf("%s", new_node->mark);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Student Inserted!\n");
}

void displayAllStudents()
{
    struct member *temp;
    temp = head;
    int count = 0;

    while (temp != NULL)
    {
        printf("\n~~~~~~~~~~~~~~~~~\n   Student %d\n~~~~~~~~~~~~~~~~~\n", (count + 1));
        printf("Name: %s\n", temp->name);
        printf("RollNo: %s\n", temp->rollNo);
        printf("Mark: %s\n", temp->mark);
        temp = temp->next;
        count++;
        printf("~~~~~~~~~~~~~~~~~\n");
    }
    printf("=========================\n");
}

void displayOnlyHighMark()
{
    struct member *temp;
    int count = 0;
    temp = head;

    printf("=========================\n");
    printf("    Only Admin Users     \n");
    printf("=========================\n");

    while (temp != NULL)
    {
        if (strcasecmp(temp->rollNo, "admin") == 0)
        {

            printf("Name: %s\n", temp->name);
            printf("rollNo: %s\n", temp->rollNo);
            printf("mark: %s\n", temp->mark);
            count++;
            printf("~~~~~~~~~~~~~~~~~\n");
        }
        temp = temp->next;
    }
    printf("=========================\n");
    printf("Total %d Admin users.\n", count);
    printf("=========================\n");
}

int main(int argc, char const *argv[])
{

    printf("\nWelcome to Christ !!!");
    int ch, noOfStud, i;

    do
    {
        printf("\n=========================\n\tMenu\n=========================\n");
        printf("1. Read N Students \n");
        printf("2. Display All Students\n");
        printf("3. Display Highest Mark\n");
        printf("4. Split the list\n");
        printf("5. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter no of students to be added: ");
            fflush(stdin);
            scanf("%d", &noOfStud);
            for (i = 0; i < noOfStud; i++)
            {
                printf("\n~~~~~~~~~~~~~~~~~\n   Student %d\n~~~~~~~~~~~~~~~~~\n", (i + 1));
                addStudent();
                printf("~~~~~~~~~~~~~~~~~\n");
            }
            break;
        case 2:
            displayAllStudents();
            break;
        case 3:
            displayOnlyHighMark();
            break;
        case 4:
            displayOnlyHighMark();
            break;
        case 5:
            printf("Bye.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (ch != 5);

    return 0;
}

struct student *disp1temp;
disp1temp = passhead;
int count = 0;

while (disp1temp != NULL)
{
    printf("\n~~~~~~~~~~~~~~~~~\n   Student %d\n~~~~~~~~~~~~~~~~~\n", (count + 1));
    printf("Name: %s\n", disp1temp->name);
    printf("RollNo: %d\n", disp1temp->rollNo);
    printf("Mark: %d\n", disp1temp->mark);
    disp1temp = disp1temp->next;
    count++;
    printf("~~~~~~~~~~~~~~~~~\n");
}
printf("=========================\n");