#define _CRT_SECURE_NO_WARNINGS 1
//�������ͨѶ¼
#include "adress book.h"
int main()
{
	int input = 0;//����ѡ��
	do
	{
		menu();//��ӡ�˵�
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input); //input����0ʱѭ������
	return 0;
}