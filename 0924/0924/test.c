#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//Ë®ÏÉ»¨Êý
int power(int n,int j)
{
	int m = n;
	for (int i = 1; i < j; i++)
	{
		n *= m;
	}
	return n;
}
void func(int i)
{
	int arr[100000] = { 0 };
	int j = 0;
	int temp = i;
	while (i >= 10)
	{
		arr[j] = i % 10;
		i /= 10;
		j++;
	}
	arr[j] = i;
	int sum = 0;
	for (int k = 0; k < j+1; k++)
	{
		sum += power(arr[k],j+1);
	}
	if (sum == temp)
	{
		printf("%d ",temp);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n+1; i++)
	{
		func(i);
	}
	return 0;
}