#define _CRT_SECURE_NO_WARNINGS 1
#include "adress_book.h"
int main()
{
	int input = 0;
	
	abook* phead = NULL;
	initbook(&phead);//��ʼ��
	Printbook(phead);
	do {
		menu();//��ӡ�˵�
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
			printf("���ڿ�����\n");
			break;
		case Exit:
			storebook(phead);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);




	return 0;

}