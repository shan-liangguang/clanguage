#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Find(int* arr1, int* arr2, int n, int i)
{
    int left = 1;
    int right = n;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (arr1[mid] > arr2[i])
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else if (arr1[mid] < arr2[i])
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        else
        {
            while (arr1[mid] == arr2[i])
            {
                mid--;
            }
            return mid + 1;
        }
    }
    return -1;
}
int main()
{
    
    
        int n;
        int m;
        scanf("%d%d", &n, &m);
        int arr1[1000002] = { -1 };
        int arr2[100002] = { 0 };
        for (int i = 1; i < n + 1; i++)
        {
            scanf("%d", &arr1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr2[i]);
        }
        for (int i = 0; i < m; i++)
        {
            printf("%d ", Find(arr1, arr2, n, i));
        }
    
    return 0;
}