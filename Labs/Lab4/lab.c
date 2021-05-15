#include <string.h>
#include <math.h>
#include <stdlib.h>
    int main()
{
    int n1, n2, n3, i, j = 0, k = 0, s1 = 0, s2 = 0, s3 = 0;
    printf("Enter the stack sizes(n1 n2 n3): ");
    scanf("%d %d %d", &n1, &n2, &n3);
    int arr1[n1];
    int arr2[n2];
    int arr3[n3];
    printf("\nInput for Stack one:-\n");
    for (i = 0; i < n1; i++)
    {
        printf("Enter cylinder height for s1 -> c%d: ", (i+1));
        scanf("%d", &arr1[i]);
        s1 += arr1[i];
    }
    printf("\nInput for Stack two:-\n");
    for (i = 0; i < n2; i++)
    {
        printf("Enter cylinder height for s2 -> c%d: ", (i + 1));
        scanf("%d", &arr2[i]);
        s2 += arr2[i];
    }
    printf("\nInput for Stack three:-\n");
    for (i = 0; i < n3; i++)
    {
        printf("Enter cylinder height for s3 -> c%d: ", (i + 1));
        scanf("%d", &arr3[i]);
        s3 += arr3[i];
    }
    printf("\n");
    i = 0;
    while (1)
    {
        if ((s1 == s2 && s2 == s3) || s1 == 0 || s2 == 0 || s3 == 0)
            break;
        if (s1 >= s2 && s1 >= s3)
            s1 -= arr1[i++];
        else if (s2 >= s1 && s2 >= s3)
            s2 -= arr2[j++];
        else
            s3 -= arr3[k++];
    }
    if (s1 == 0 || s2 == 0 || s3 == 0)
        printf("Output Value : 0\n");
    else
    {
        printf("Output Value : %d\n", s1);
    }
    printf("\n");
    return 0;
}