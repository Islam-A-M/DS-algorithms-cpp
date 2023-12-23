#include <iostream>
// #include "stdafx.h"
#include <stdlib.h>
using namespace std;
int main()
{
    int *A, n, ch, x, i, j;
    printf("Enter dimension");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    do
    {
        switch (ch)
        {
        case 1:
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &A[i - 1]);
            }

            break;
        case 2:
            printf("Enter Indices");
            scanf("%d%d", &i, &j);
            if (i == j)
            {
                printf("%d", A[i - 1]);
            }
            else
            {
                printf("0");
            }

            break;

        case 3:
            printf("Enter row,column and element");
            scanf("%d%d%d", &i, &j, &x);
            if (i == j)
                A[i - 1] = x;
            break;

        case 4:
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; i <= n; j++)
                {
                    if (j==i)
                    {
                        printf("%d",A[i-1]);
                    }else{
                        printf("0 ");
                    }
                    
                }
            }

        default:
            break;
        }
    } while (/* condition */);

    return 0;
}