#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//高精度阶乘
int main()
{
	int n = 0;
	scanf("%d", &n);
	int up = 0;
	int k = 1;
	int arr[100000] = { 0 };
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int count = 0;
			arr[j] *= i;
			arr[j] += up;
			up = arr[j] / 10;
			arr[j] = arr[j] % 10;
			if (j == k-1 && up>0)
			{
				k++;
				arr[j+1] = up % 10;
				up /= 10;
				while (1)
				{
					if (up > 0)
					{
						count++;
						k++;
						arr[j + 1 + count] = up % 10;
						up /= 10;
					}
					else
						break;
					
				}
				break;
			}
		}
	}
	printf("%dĽ׳Ϊ", n);
	for (int i = k-1; i>=0; i--)
	{
		printf("%d",arr[i]);
	}
	return 0;
}

//6402373705728000(18)
//121645100408832000(19)
//2432902008176640000(20)
