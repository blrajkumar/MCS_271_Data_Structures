#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50

struct student
{
    char name[NAME_SIZE];
    int rollNo;
    int mark;
    struct student *next;
};

struct student *head = NULL;
struct student *passhead = NULL;
struct student *failhead = NULL;

void addStudent()
{
    struct student *new_node;
    struct student *temp;
    temp = head;

    new_node = (struct student *)malloc(sizeof(struct student));
    printf("Enter Name: ");
    fflush(stdin);
    scanf("%s", new_node->name);
    printf("Enter RollNo: ");
    fflush(stdin);
    scanf("%d", &new_node->rollNo);
    printf("Enter Mark: ");
    fflush(stdin);
    scanf("%d", &new_node->mark);

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
    struct student *temp;
    temp = head;
    int count = 0;

    while (temp != NULL)
    {
        printf("\n~~~~~~~~~~~~~~~~~\n   Student %d\n~~~~~~~~~~~~~~~~~\n", (count + 1));
        printf("Name: %s\n", temp->name);
        printf("RollNo: %d\n", temp->rollNo);
        printf("Mark: %d\n", temp->mark);
        temp = temp->next;
        count++;
        printf("~~~~~~~~~~~~~~~~~\n");
    }
    printf("=========================\n");
}

void displayOnlyHighMark()
{
    struct student *temp;
    int high_sid = 0;
    int high_mvalue = 0;
    char high_name[20];
    int count = 0;
    temp = head;

    while (temp != NULL)
    {
        if (count == 0)
        {
            high_sid = temp->rollNo;
            high_mvalue = temp->mark;
            strcpy(high_name, temp->name);
            count++;
        }
        else
        {
            if (temp->mark > high_mvalue)
            {
                high_sid = temp->rollNo;
                high_mvalue = temp->mark;
                strcpy(high_name, temp->name);
            }
        }
        temp = temp->next;
    }
    if (count > 0)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("   High Mark Student  \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Roll No: %d\n", high_sid);
        printf("Name: %s\n", high_name);
        printf("Mark: %d\n", high_mvalue);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    else
    {
        printf("The db is empty");
    }
}

void splitStudents()
{
    struct student *temp;
    struct student *passtemp;
    struct student *failtemp;
    temp = head;

    while (temp != NULL)
    {
        struct student *new_node;
        new_node = (struct student *)malloc(sizeof(struct student));
        passtemp = passhead;
        failtemp = failhead;
        
        strcpy(new_node->name, temp->name);
        new_node->rollNo = temp->rollNo;
        new_node->mark = temp->mark;

        if (new_node->mark < 40)
        {
            if (failhead == NULL)
            {
                failhead = new_node;
            }
            else
            {
                while (failtemp->next != NULL)
                {
                    failtemp = failtemp->next;
                }
                failtemp->next = new_node;
            }
        }
        else
        {
            if (passhead == NULL)
            {
                passhead = new_node;
            }
            else
            {
                while (passtemp->next != NULL)
                {
                    passtemp = passtemp->next;
                }
                passtemp->next = new_node;
            }
        }
        temp = temp->next;
    }

    struct student *disp1temp;
    disp1temp = passhead;
    int count = 0;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("   Passed Students  \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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
    printf("~~~~~~~~~~End~~~~~~~~~~~\n");
    printf("=========================\n");

    struct student *disp2temp;
    disp2temp = failhead;
    int count2 = 0;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("   Failed Students  \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while (disp2temp != NULL)
    {
        printf("\n~~~~~~~~~~~~~~~~~\n   Student %d\n~~~~~~~~~~~~~~~~~\n", (count2 + 1));
        printf("Name: %s\n", disp2temp->name);
        printf("RollNo: %d\n", disp2temp->rollNo);
        printf("Mark: %d\n", disp2temp->mark);
        disp2temp = disp2temp->next;
        count2++;
        printf("~~~~~~~~~~~~~~~~~\n");
    }
    printf("~~~~~~~~~~End~~~~~~~~~~~\n");
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
            splitStudents();
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