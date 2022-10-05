#define _CRT_SECURE_NO_WARNINGS 1
//无链表的通讯录
#include "adress book.h"
int main()
{
	int input = 0;//接受选择
	do
	{
		menu();//打印菜单
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Add()
			break;
		case delete:
			break;
		case search:
			break;
		case revise:
			break;
		case sort:
			break;
		case exit:
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input); //input等于0时循环结束
	return 0;
}