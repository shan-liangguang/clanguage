#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[104][104] = { 0 };
int main()
{
    int n, m, k;
    int x1[25] = { 0 };
    int y1[25] = { 0 };
    int x2[5] = { 0 };
    int y2[5] = { 0 };
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 2; j < n + 2; j++)
        {
            arr[i][j] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x1[i], &y1[i]);
        arr[x1[i] + 1][y1[i] + 1] = 0;
        arr[x1[i]][y1[i] + 1] = 0;
        arr[x1[i] - 1][y1[i] + 1] = 0;
        arr[x1[i] + 2][y1[i] + 1] = 0;
        arr[x1[i] + 3][y1[i] + 1] = 0;
        arr[x1[i] + 1][y1[i]] = 0;
        arr[x1[i] + 1][y1[i] - 1] = 0;
        arr[x1[i] + 1][y1[i] + 2] = 0;
        arr[x1[i] + 1][y1[i] + 3] = 0;
        arr[x1[i]] [y1[i]] = 0;
        arr[x1[i]][y1[i] + 2] = 0;
        arr[x1[i] + 2][y1[i] ] = 0;
        arr[x1[i] + 2][y1[i]+2] = 0;

    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &x2[i], &y2[i]);
        for (int j = x2[i] ; j < x2[i] + 5; j++)
        {
            for (int f = y2[i] ; f < y2[i] + 5; f++)
            {
                arr[j][f] = 0;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 2; j < n + 2; j++)
        {
            count += arr[i][j];
        }
    }
    printf("%d", count);
    return 0;
}