#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Add(int x, int y)
{
	
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mult(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
void cacal(int (*pa)(int, int), int (*ps)(int, int), int (*pm)(int, int), int (*pd)(int, int))
{
	int n;
	again:
		scanf("%d", &n);
		if (n>=1&&n<=4)
		{
			printf("��������������");
			int x, y;
			scanf("%d%d", &x, &y);
			int (*P[5])(int, int) = { NULL,pa,ps,pm,pd };
			printf("%d",P[n](x, y));
		}
		else if (n == 0)
		{
			printf("�˳�����");
		}
		else
		{
			printf("������������ȷ������");
			goto again;
		}
}
void menu()
{
	printf("***********    0.exit  ***********\n");
	printf("*****1.add  2.sub ****************\n");
	printf("********* 3.mult  ****************\n");
	printf("********** 4.div *****************\n");
	printf("**********************************\n");
	printf("��ѡ��-->:");
}
int main()
{
	menu();
	cacal(Add, sub, mult, div);
	return 0;
}
