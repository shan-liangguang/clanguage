#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)//实现strstr函数
{
	assert(str1);
	assert(str2);
	if (*str2 == '\0')//如果str2第一个元素就为\0，就返回str1
	{
		return (char*)str1;
	}
	const char* tmp2 = str2;//记录下初始的str2
	//首先我得遍历str1,找到与str2第一个元素相同的元素
	again:
	while (*str1++ != *str2)
	{
		if (*str1 == '\0')
		{
			return NULL;
		}
	}
	str1--;
	const char* tmp1 = str1;//记录下第一个相同的地址，方便后面再从下一个开始找
	while (*str2)//再看看接下来的元素是否也跟str2相同
	{
		if (*str1 == '\0')
		{
			return NULL;
		}
		str1++;
		str2++;

		if (*str1 != *str2)
		{
			break;
		}
	}
	if (*str2 == '\0')
	{
		return (char*)tmp1;
	}
	else
	{
		str1 = tmp1+1;
		str2 = tmp2;
		goto again;
	}
}
void* my_memcpy(void* dest, const void* source,unsigned int num)
{
	void* ret = dest;
	assert(dest && source);
	for (int i = 0; i < num; i++)
	{
		*((char*)dest)++ = *((char*)source)++;
	}
	return ret;
}
int main()
{
	//char str1[20] = "abcdefsda";
	//char str2[10] = { '\0' };
	//printf("%s", my_strstr(str1, str2));
	//return 0;
	int arr1[20] = { 1,2,31,12,32,43,2,3131,12,32 };
	int arr2[10] = { 0 };
	memcpy(arr1, arr1+1, 40);
	for (int j = 0; j < 10; j++)
	{
		printf("%d ", arr1[j]);
	}
}