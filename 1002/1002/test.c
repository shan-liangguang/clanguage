#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define h 3
#define l 4
//杨氏矩阵
void find(int n, int arr[h][l])
{
	int origin1 = 0;
	int origin2 = l - 1;
	again:
	while (arr[origin1][origin2] > n && origin1 <h&&origin2>-1)
	{
		origin2--;
	}
	while (arr[origin1][origin2]<n && origin1<h && origin2 > -1)
	{
		origin1++;
		goto again;
	}
	if (origin1 > h-1 || origin2 < 0)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，为第%d行，第%d列\n",origin1+1, origin2+1);
	}
}
int main()

{
	while (1)
	{
		int arr[h][l] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
		int n;
		scanf("%d", &n);
		find(n, arr);
	}
	return 0;
}