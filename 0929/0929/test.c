#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//Ê¹ÓÃqsortº¯Êý
int compare_int(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}
void print_int(int*a,int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(a+i));
	}
}
int main()
{
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), compare_int);
	print_int(&arr[0], sz);
	return 0;
}