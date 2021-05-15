/**********************
 * Name : Rajkumar B L
 * Reg  : 2047120
 * Lab  : 09
 * Program : Topological Sort
 * ********************/

#include <stdio.h>

int main()
{

    printf("\n****************************\n*  Name : Rajkumar B L     *\n*  Reg  : 2047120          *\n*  Lab  : 09               *\n*  Prg  : Topological Sort *\n****************************\n\n");

    int i, j, k, n, a[10][10], indeg[10], flag[10], count = 0;

    printf("Enter the no of vertices: ");

    scanf("%d", &n);

    printf("\nLets draw the graph :-\n");

    for (i = 0; i < n; i++)
    {

        printf("Enter row %d : ", i + 1);

        for (j = 0; j < n; j++)

            scanf("%d", &a[i][j]);
    }

    for (i = 0; i < n; i++)
    {

        indeg[i] = 0;

        flag[i] = 0;
    }

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            indeg[i] = indeg[i] + a[j][i];

    printf("\nThe topological order for the entered graph is: ");

    while (count < n)
    {

        for (k = 0; k < n; k++)
        {

            if ((indeg[k] == 0) && (flag[k] == 0))
            {

                printf("%d ", (k + 1));

                flag[k] = 1;
            }

            for (i = 0; i < n; i++)
            {

                if (a[i][k] == 1)

                    indeg[k]--;
            }
        }

        count++;
    }
    printf("\n\n");
    return 0;
}

