#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)//ʵ��strstr����
{
	assert(str1);
	assert(str2);
	if (*str2 == '\0')//���str2��һ��Ԫ�ؾ�Ϊ\0���ͷ���str1
	{
		return (char*)str1;
	}
	const char* tmp2 = str2;//��¼�³�ʼ��str2
	//�����ҵñ���str1,�ҵ���str2��һ��Ԫ����ͬ��Ԫ��
	again:
	while (*str1++ != *str2)
	{
		if (*str1 == '\0')
		{
			return NULL;
		}
	}
	str1--;
	const char* tmp1 = str1;//��¼�µ�һ����ͬ�ĵ�ַ����������ٴ���һ����ʼ��
	while (*str2)//�ٿ�����������Ԫ���Ƿ�Ҳ��str2��ͬ
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