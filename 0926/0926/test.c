#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//打印杨辉三角
void C(int i, int j)//组合公式
{
	if (j == 0)
	{
		printf("1 ");
	}
	else
	{
		int up = 1;
		int down = 1;
		for (int k = 1; k <= j; i--)
		{
			up *= i;
			k++;
		}
		for (int k = 1; k < j; j--)
		{
			down *= j;
		}
		int result = up / down;
		printf("%3d ", result);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			C(i, j);
		}
		printf("\n");
	}
	return 0;
}