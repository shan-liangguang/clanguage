#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//Compare(const void* a, const void* b)
//{
//    return *((int*)a) - *((int*)b);
//}
//int main()
//{
//    int n = 0;
//    int arr[101] = { 0 };
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    qsort(arr, n, sizeof(int), Compare);
//    int arr1[101] = { 0 };
//    int count = 0;
//    for (i = 0; i < n; i++)
//    {
//        while (arr[i + 1] != arr[i])
//        {
//            arr1[count] = arr[i];
//            count++;
//        }
//    }
//    printf("%d\n", count + 1);
//    for (i = 0; i < count + 1; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 2; i < n; i++)
//    {
//        if (n % i == 0)
//        {
//            printf("%d", n / i);
//            break;
//        }
//    }
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int sum[7] = { 0 };
//    for (int i = 0; i < 7; i++)
//    {
//        scanf("%d%d", &a, &b);
//        sum[i] = a + b;
//    }
//    int max = 0;
//    for (int i = 0; i < 7; i++)
//    {
//        if (i == 0)
//        {
//            max = i + 1;
//        }
//        else if (sum[i] > sum[max - 1])
//        {
//            max = i + 1;
//        }
//    }
//    printf("%d", max);
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int leftover = 0;
//    int arr[12] = { 0 };
//    int count = 0;
//    int a = 0;
//    for (int i = 0; i < 12; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (arr[i] > (leftover + 300))
//        {
//            printf("%d", -(i + 1));
//            a = 1;
//            break;
//        }
//        else
//        {
//            leftover = leftover + 300 - arr[i];
//            if ((leftover / 100) > 0)
//            {
//                count += leftover / 100;
//                leftover = leftover % 100;
//            }
//        }
//    }
//    if (a != 1)
//    {
//        int sum = 120 * count + leftover;
//        printf("%d", sum);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    int i, j, k, l, n, min = 0, h;
//    scanf("%d", &n);
//    char ch[100000];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s", ch);
//        scanf("%d", &k);
//        l = strlen(ch);
//        min = -1;
//        int zimu[26] = { 0 };
//        h = 0;
//        for (j = 0; j < l; j++)
//        {
//            zimu[ch[j] - 97]++;
//            while (zimu[ch[j] - 97] == k)
//            {
//                zimu[ch[h] - 97] -= 1;
//                if (j - h + 1 < min || min == -1)
//                {
//                    min = j - h + 1;
//                }
//                h++;
//            }
//        }
//        printf("%d\n", min);
//    }
//    return 0;
//}
#include <stdio.h>
int main()
{
	long long n;
	scanf("%d", &n);
	return 0;
}