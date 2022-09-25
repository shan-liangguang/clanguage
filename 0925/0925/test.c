#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reverse(char* str)
//{
//	assert(str);
//	char* left = str;
//	char* right = str + strlen(str)-1;
//	while (right >= left)
//	{
//		char temp;
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//	printf("%s", str);
//}
//int main()
//{
//	char str[10000];
//	scanf("%s", str);
//	reverse(str);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char str[100];
//	int n;//n为奇数 
//	again:
//	scanf("%d", &n);
//	if (n % 2 == 0)
//	{
//		printf("请输入奇数:");
//		goto again;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		str[i] = ' ';
//	}
//	int middle = n / 2 + 1;
//	int left = middle -1;
//	int right = middle-1;
//	str[n] = '\0';
//	for (int j = 0; j < middle; j++)
//	{
//		str[left] = '*';
//		str[right] = '*';
//		printf("%s", str);
//		left--;
//		right++;
//		printf("\n");
//	}
//	while (left < right)
//	{
//		str[left+1] = ' ';
//		str[right-1] = ' ';
//		printf("%s", str);
//		left++;
//		right--;
//		printf("\n");
//	}
//	return 0;
//}
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，n元能喝多少瓶汽水
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	int x = 2;
	sum += n;
	int leftover = 0;
	while (n / x >= 1)
	{
		sum += (n / x);
		leftover = n % x;
		n = n / x + leftover;
	}
	printf("%d", sum);
	return 0;
}
//其实运用数学知识可证明sum = 2n -1;