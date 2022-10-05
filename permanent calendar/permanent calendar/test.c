#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//思路：已知2022 10 05 为星期三->10 01 为星期6
//1月有31天，2月有28或29天（闰年为29），3月有31
//4:30  5:31   6:30  7:31  8:31  9:30  10:31 11:30  12:31 闰年有366天 平年有365天
//百度闰年判断：能被4整除却不能被100整除或能被400整除的年份就是闰年！
//那么输入2019 5 23 输出结果为什么？
//首先算出它第五月份第一天与今天距离多少天，在模7，就可以算出星期几
void Print(int x,int n,int d)//n为第一天为星期几,x为这个月一共有多少天
{
	int count = 0;
	int arr[31] = { 0 };//存放第几日
	if (n == 0)
	{
		n = 7;
	}
	for (int i = 1; i <n; i++)
	{
		printf("%-8s", " ");//打印第一天前面的空格
		count++;
	}
	for (int i = 0; i < x; i++)
	{
		arr[i] = i+1;
		if (arr[i] == d)
		{
			printf("*%-8d", d);
		}
		else if (arr[i] == d + 1&&count!=0)
		{
			printf("%-7d", arr[i]);
		}
		else
		{
			printf("%-8d", arr[i]);
		}
		count++;
		if (count == 7)
		{
			printf("\n");
			count = 0;
		}
	}
	

}
int is_leap_year(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
	{
		return 366;
	}
	return 365;
}
int main()
{
	printf("请输入年月日->:");
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", "一", "二", "三", "四", "五", "六", "日");
	int day1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//润年
	int day2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;//计算相差多少天
	if (y == 2022)
	{
		if (m > 10)
		{
			for (int i = 10; i < m; i++)
			{
				sum += day2[i - 1];
			}
			Print(day2[m - 1], (sum % 7 + 6) % 7, d);
		}
		else if (m < 10)
		{
			for (int i = m; i < 10; i++)
			{
				sum += day2[i - 1];
			}
			Print(day2[m - 1], 6 - sum % 7, d);
		}
		else
		{
			Print(day2[10-1],6,d);
		}
	}
	else if (y > 2022)
	{
		for (int i = 2022; i <= y; i++)
		{
			sum += is_leap_year(i);
		}
		for (int i = 0; i < 9; i++)
		{
			sum -= day2[i];
		}
		for (int i = m - 1; i < 12; i++)
		{
			if (is_leap_year(y) == 365)
			{
				sum -= day2[i];
			}
			else
			{
				sum -= day1[i];
			}
		}
		if (is_leap_year(y) == 365)
		{
			Print(day2[m - 1], (sum % 7 + 6) % 7, d);
		}
		else
		{
			Print(day1[m - 1], (sum % 7 + 6) % 7, d);
		}
	}
	else
	{
		for (int i = y; i <= 2022; i++)
		{
			sum+= is_leap_year(i);
		}
		for (int i = 9; i < 12; i++)
		{
			sum -= day2[i];
		}
		for (int i = 0; i < m-1; i++)
		{
			if (is_leap_year(y) == 365)
			{
				sum -= day2[i];
			}
			else
			{
				sum -= day1[i];
			}
		}
		if (is_leap_year(y) == 365)
		{
			Print(day2[m - 1], 6 - sum % 7, d);
		}
		else
		{
			Print(day1[m - 1], 6 - sum % 7, d);
		}
	}
	return 0;

}