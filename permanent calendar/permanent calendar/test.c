#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//˼·����֪2022 10 05 Ϊ������->10 01 Ϊ����6
//1����31�죬2����28��29�죨����Ϊ29����3����31
//4:30  5:31   6:30  7:31  8:31  9:30  10:31 11:30  12:31 ������366�� ƽ����365��
//�ٶ������жϣ��ܱ�4����ȴ���ܱ�100�������ܱ�400��������ݾ������꣡
//��ô����2019 5 23 ������Ϊʲô��
//��������������·ݵ�һ��������������죬��ģ7���Ϳ���������ڼ�
void Print(int x,int n,int d)//nΪ��һ��Ϊ���ڼ�,xΪ�����һ���ж�����
{
	int count = 0;
	int arr[31] = { 0 };//��ŵڼ���
	if (n == 0)
	{
		n = 7;
	}
	for (int i = 1; i <n; i++)
	{
		printf("%-8s", " ");//��ӡ��һ��ǰ��Ŀո�
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
	printf("������������->:");
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);
	printf("%-8s%-8s%-8s%-8s%-8s%-8s%-8s\n", "һ", "��", "��", "��", "��", "��", "��");
	int day1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//����
	int day2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;//������������
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