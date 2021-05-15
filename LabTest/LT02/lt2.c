/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : Test 02
 * ********************/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 30

int h[TABLE_SIZE] = {NULL};

void insert()
{

    int key, index, i, flag = 0, hkey;
    int temp, remainder, sum = 0;

    printf("Enter a value to insert: ");
    scanf("%d", &key);

    temp = key;
    while (temp != 0)
    {
        remainder = temp % 10;
        sum = sum + remainder;
        temp = temp / 10;
    }

    hkey = sum % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {

        index = (hkey + i) % TABLE_SIZE;

        if (h[index] == NULL)
        {
            h[index] = key;
            printf("Element %d successfully inserterd at index --> %d", key, index);
            break;
        }
        printf("Element %d Collision occured at index --> : %d\n", key, index);
    }

    if (i == TABLE_SIZE)
        printf("\nElement cannot be inserted\n");
    printf("\n");
}
void search()
{
    int key, index, i, flag = 0, hkey;
    int temp, remainder, sum = 0;
    int comparison = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    temp = key;
    while (temp != 0)
    {
        remainder = temp % 10;
        sum = sum + remainder;
        temp = temp / 10;
    }

    hkey = sum % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;
        comparison = comparison + 1;
        if (h[index] == key)
        {
            printf("Element is found at index --> %d", index);
            break;
        }
        if (comparison>1 && h[index] == NULL)
        {
            printf("\nElement is not found");
            comparison = comparison - 1;
            break;
        }
    }
    if (i == TABLE_SIZE)
        printf("\nElement is not found");
    if (comparison>0)
    {
        printf("\nTotal number of comparisons --> %d", comparison);
    }

    printf("\n");
}

void display()
{

    int i;

    printf("\nElements in the hash table are:-\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("\nEntries at index %d --> : ", i);
        if (h[i] == NULL)
        {
            printf("Empty!");
        }

        else
        {
            printf("%d", h[i]);
        }
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int opt, i;
    printf("\n*************************\n*  Name : Rajkumar B L  *\n*  Reg  : 2047120       *\n*  Lab  : Test 02       *\n*************************\n");
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
