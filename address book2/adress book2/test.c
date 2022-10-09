#define _CRT_SECURE_NO_WARNINGS 1
#include "adress_book.h"
int main()
{
	int input = 0;
	
	abook* phead = NULL;
	initbook(&phead);//初始化
	Printbook(phead);
	do {
		menu();//打印菜单
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Add(&phead);
			Printbook(phead);
			break;
		case delete:
			Delete(&phead);
			Printbook(phead);
			break;
		case search:
			Search(phead);
			break;
		case revise:
			Revise(&phead);
			Printbook(phead);
			break;
		case sort:
			printf("正在开发中\n");
			break;
		case Exit:
			storebook(phead);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);




	return 0;

}