#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int l = 0;
        int r = 0;
        scanf("%d%d", &l, &r);
        int sum = 0;
        int min, max;
        for (int j = 0; j < 13; j++)
        {
            if (l >= pow(10, j)||l==0)
            {
                min = j + 1;
                break;
            }
            else if (l == 0)
            {
                min = 1;
            }
        }
        for (int j = 0; j < 13; j++)
        {
            if (r <= pow(10, j)||r==0)
            {
                max = j + 1;
                break;
            }
        }
        for (int j = min; j < max; j++)
        {
            if (l == 0 && r != 0)
            {
                sum++;
            }
            for (int k =(double) pow(10, min-1) / min; k <=(double) pow(10, (min))/min; k++)
            {
                if (k * min >= l && k * min <= r)
                {
                    sum++;
                }
            }
        }
        printf("%d", sum);
    }
    return 0;
}