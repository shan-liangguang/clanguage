#define _CRT_SECURE_NO_WARNINGS 1
//�������ͨѶ¼
#include "adress book.h"
int main()
{
	int input = 0;//����ѡ��
	abook book;
	initbook(&book);//��ʼ��ͨѶ¼������ͨѶ¼����
	printbook(&book);
	do
	{
		menu();//��ӡ�˵�
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
			printf("��������Ҫ���ҵ���->:");
			scanf("%s", arr);
			tmp = Search_by_name(&book,arr);
			if (tmp == -1)
			{
				printf("�����ڴ���\n");
			}
			else
			{
				printf("�ҵ���\n");
				Printsigle(tmp, &book);
			}
			break;
		case revise:
			printf("��������Ҫ�޸ĵ��˵�����->:");
			scanf("%s", arr);
			Revise(&book, arr);
			printbook(&book);
			break;
		case sort:
			printf("���ڿ�����\n");
			break;
		case exit:
			storedata(&book);
			Free(&book);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input); //input����0ʱѭ������
	return 0;
}