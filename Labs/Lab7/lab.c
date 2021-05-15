/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : 07
 * Program : Hashing
 * ********************/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *head[TABLE_SIZE] = {NULL}, *c;
void insert()
{
    int key, value;
    printf("Enter a value to insert: ");
    scanf("%d", &value);
    key = value % TABLE_SIZE;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (head[key] == NULL)
        head[key] = newnode;
    else
    {
        c = head[key];
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = newnode;
    }
}

void search()
{
    int key, index;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    index = key % TABLE_SIZE;
    if (head[index] == NULL)
        printf("Search element not found!");
    else
    {
        for (c = head[index]; c != NULL; c = c->next)
        {
            if (c->data == key)
            {
                printf("Search element found!");
                break;
            }
        }

        if (c == NULL)
            printf("Search element not found!");
    }
}

void display()

{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("\nEntries at index %d: ", i);
        if (head[i] == NULL)
        {
            printf("No Hash Entry!");
            //return;
        }

        else
        {
            for (c = head[i]; c != NULL; c = c->next)
                printf("%d->", c->data);
        }
    }
    printf("\n");
}

int main()
{
    int opt, key, i;

    printf("\n*************************\n*  Name : Rajkumar B L  *\n*  Reg  : 2047120       *\n*  Lab  : 07            *\n*  Prg  : Hashing       *\n*************************");
    while (1)
    {
        printf("\n=========================\n         Menu\n=========================\n1.Insert\n2.Display\n3.Search\n4.Exit\n========================\nEnter choice:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter Valid Choice!");
        }
    }

    return 0;
}