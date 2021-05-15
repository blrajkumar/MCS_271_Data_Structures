/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : 05
 * Program : Shell Sort
 * ********************/
#include <stdio.h>

void shellSort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (arr[k + i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[30];
    int k, size;
    printf("Enter number of elements to be sorted : ");
    scanf("%d", &size);
    printf("\nEnter %d numbers: \n", size);
    for (k = 0; k < size; k++)
    {
        scanf("%d", &data[k]);
    }
    printf("\nArray before sorting: \n");
    printArray(data, size);
    shellSort(data, size);
    printf("\nArray After sorting: \n");
    printArray(data, size);
    printf("\n");
}