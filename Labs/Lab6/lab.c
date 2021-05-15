/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : 06
 * Program : Radix Sort
 * ********************/
#include <stdio.h>
int get_max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void radix_sort(int a[], int n)
{
    int bucket[10][10], bucket_cnt[10];
    int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
    lar = get_max(a, n);
    while (lar > 0)
    {
        NOP++;
        lar /= 10;
    }
    for (pass = 0; pass < NOP; pass++)
    {
        for (i = 0; i < 10; i++)
        {
            bucket_cnt[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = a[i];
            bucket_cnt[r] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < bucket_cnt[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        printf("After pass %d : ", pass + 1);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        divisor *= 10;
        printf("\n");
    }
}
int main()
{
    printf("\n*************************\n*  Name : Rajkumar B L  *\n*  Reg  : 2047120       *\n*  Lab  : 06            *\n*  Prg  : Radix Sort    *\n*************************\n\n");

    int i, n, a[10];
    printf("Enter the number of items to be sorted: ");
    scanf("%d", &n);
    printf("Enter items  : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    radix_sort(a, n);
    printf("Sorted items : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");
    return 0;
}