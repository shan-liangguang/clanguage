#define _CRT_SECURE_NO_WARNINGS 1
//无链表的通讯录
#include "adress book.h"
int main()
{
	int input = 0;//接受选择
	abook book;
	initbook(&book);//初始化通讯录，申请通讯录容量
	printbook(&book);
	do
	{
		menu();//打印菜单
		scanf("%d", &input);
		char arr[10] = { 0 };
		int tmp = 0;
		switch (input)
		{
		case add:
			Add(&book);
			printbook(&book);
			break;
		case delete:
			Delete(&book);
			break;
		case search:
			printf("请输入你要查找的人->:");
			scanf("%s", arr);
			tmp = Search_by_name(&book,arr);
			if (tmp == -1)
			{
				printf("不存在此人\n");
			}
			else
			{
				printf("找到了\n");
				Printsigle(tmp, &book);
			}
			break;
		case revise:
			printf("请输入你要修改的人的名字->:");
			scanf("%s", arr);
			Revise(&book, arr);
			printbook(&book);
			break;
		case sort:
			printf("正在开发中\n");
			break;
		case exit:
			storedata(&book);
			Free(&book);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input); //input等于0时循环结束
	return 0;
}