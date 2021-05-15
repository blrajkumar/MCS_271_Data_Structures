#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define TYPE_SIZE 10
#define STATUS_SIZE 10

struct member
{
    char name[NAME_SIZE];
    char type[TYPE_SIZE];
    char status[STATUS_SIZE];
    struct member *next;
};

struct member *head = NULL;

void addMember()
{
    struct member *ptr;
    struct member *temp;
    temp = head;

    ptr = (struct member *)malloc(sizeof(struct member));
    printf("Name: ");
    fflush(stdin);
    scanf("%s", ptr->name);
    printf("Type: ");
    fflush(stdin);
    scanf("%s", ptr->type);
    printf("Status: ");
    fflush(stdin);
    scanf("%s", ptr->status);

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void deleteMember()
{
    struct member *temp, *previous;
    temp = head;
    previous = head;
    int flag = 0;

    char memberToBeDeletedName[NAME_SIZE];
    fflush(stdin);
    printf("Enter member name to be deleted: ");
    scanf("%s", memberToBeDeletedName);

    while (temp != NULL)
    {
        if (strcmp(temp->name, memberToBeDeletedName) == 0)
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
    struct member *temp;
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
    struct member *temp;
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
    struct member *temp;
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
    printf("================================================\n");
    printf("            Welcome to the WhatsApp             \n");
    printf("================================================\n");
    int ch;

    do
    {
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. All Users\n");
        printf("4. Admin Users\n");
        printf("5. Available Users\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addMember();
            displayAllUsers();
            break;
        case 2:
            deleteMember();
            displayAllUsers();
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
