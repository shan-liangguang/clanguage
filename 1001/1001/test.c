#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
	char name[20];
	int age;
	int id;
};
int id_sort(void* a, void* b)
{
	return ((struct stu*)a)->id - ((struct stu*)b)->id;
}//ÉýÐò
int name_sort(void* a, void* b)
{
	return strcmp(((struct stu*)a)->name, ((struct stu*)a)->name);
}
//Ä£·Âqsortº¯Êý
void swap(int sz, char* a, char* b)
{
	for (int i = 0; i < sz; i++)
	{
		char tmp;
		tmp = *(a+i);
		*(a+i) = *(b+i);
		*(b+i) = tmp;
	}
}
void bubble_sort(void* base, int num, int sz, int (*cmp)(const void*, const void*))
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i-1; j++)
		{
			if (cmp((char*)base+j*sz, (char*)base +(j+1)*sz)> 0)
			{
				swap(sz, (char*)base+j*sz, (char*)base +(j+1)*sz);
			}
		}
	}
}
int char_sort(void* a, void* b)
{
	return *((char*)a) - *((char*)b);
}
int main()
{
	//struct stu arr[3] = { {"zhangsan",10,10000 }, {"lisi",11,10200},{"wangwu",9,10010} };
	///*qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), id_sort);*/
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), name_sort);
	/*char str[10] = "cbanbadcx";
	bubble_sort(str, strlen(str), sizeof(str[0]), char_sort);*/
	char str[] = "abcdef";
	printf("%d", strlen(&str));
	printf("%d", strlen(str));
	return 0;
}
