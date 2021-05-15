#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define TYPE_SIZE 10
#define STATUS_SIZE 10

struct student
{
    char name[NAME_SIZE];
    char type[TYPE_SIZE];
    char status[STATUS_SIZE];
    struct student *next;
};

struct student *head = NULL;

void addMember()
{
    struct student *new_node;
    struct student *temp;
    temp = head;

    new_node = (struct student *)malloc(sizeof(struct student));
    printf("Name: ");
    fflush(stdin);
    scanf("%s", new_node->name);
    printf("Type: ");
    fflush(stdin);
    scanf("%s", new_node->type);
    printf("Status: ");
    fflush(stdin);
    scanf("%s", new_node->status);

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
    printf("Member Inserted!\n");
}

void deleteMember()
{
    struct student *temp, *previous;
    temp = head;
    previous = head;
    int flag = 0;

    char mem_name[NAME_SIZE];
    fflush(stdin);
    printf("Enter member name to be deleted: ");
    scanf("%s", mem_name);

    while (temp != NULL)
    {
        if (strcmp(temp->name, mem_name) == 0)
        {
            if (temp != head)
                previous->next = temp->next;
            else
                head = temp->next;
            printf("Member deleted.\n");
            flag = 1;
        }
        previous = temp;
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("Member not found!\n");
    }
}

void displayAllUsers()
{
    struct student *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("=========================\n");
        printf("Name: %s\n", temp->name);
        printf("Type: %s\n", temp->type);
        printf("Status: %s\n", temp->status);
        temp = temp->next;
    }
    printf("=========================\n");
}

void displayOnlyAdminUsers()
{
    struct student *temp;
    int count = 0;
    temp = head;

    printf("=========================\n");
    printf("    Only Admin Users     \n");
    printf("=========================\n");

    while (temp != NULL)
    {
        if (strcasecmp(temp->type, "admin") == 0)
        {
            printf("=========================\n");
            printf("Name: %s\n", temp->name);
            printf("Type: %s\n", temp->type);
            printf("Status: %s\n", temp->status);
            count++;
        }
        temp = temp->next;
    }
    printf("=========================\n");
    printf("Total %d Admin users.\n", count);
    printf("=========================\n");
}

void displayOnlyAvailableUsers()
{
    struct student *temp;
    int count = 0;
    temp = head;
    printf("=========================\n");
    printf("  Only Available Users   \n");
    printf("=========================\n");

    while (temp != NULL)
    {
        if (strcasecmp(temp->status, "available") == 0)
        {
            printf("=========================\n");
            printf("Name: %s\n", temp->name);
            printf("Type: %s\n", temp->type);
            printf("Status: %s\n", temp->status);
            count++;
        }
        temp = temp->next;
    }
    printf("=========================\n");
    printf("Total %d Available users.\n", count);
    printf("=========================\n");
}

int main(int argc, char const *argv[])
{
    
    printf("\nWelcome to WhatsApp!!!");
    int ch;

    do
    {
        printf("\n=====================\n\tMenu\n=====================\n");
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. All Users\n");
        printf("4. Admin Users\n");
        printf("5. Available Users\n");
        printf("6. Exit\n");
        printf("=====================\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addMember();
            break;
        case 2:
            deleteMember();
            //displayAllUsers();
            break;
        case 3:
            displayAllUsers();
            break;
        case 4:
            displayOnlyAdminUsers();
            break;
        case 5:
            displayOnlyAvailableUsers();
            break;
        case 6:
            printf("Bye.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (ch != 6);

    return 0;
}
