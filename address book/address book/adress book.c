#define _CRT_SECURE_NO_WARNINGS 1
#include "adress book.h"
void menu()//�˵�
{
	//���ӣ�ɾ������ѯ���޸Ĳ��������������
	printf("          ͨѶ¼             \n");
	printf("     1.����     2.ɾ��       \n");
	printf("     3.��ѯ     4.�޸�       \n");
	printf("     5.����     0.�˳�       \n");
	printf("��ѡ��->:");
}
void initbook(abook* pb)//��ʼ��ͨѶ¼�Ͷ�ȡ�ļ���Ϣ
{
	pb->data = (peo*)malloc(5 * sizeof(peo));//һ��ʼ�����������5������Ϣ�Ŀռ�
	pb->d_max = 5;
	pb->d_now = 0;
	FILE* pf = fopen("adress book.dat", "r");
	if (pf == NULL)
	{
		perror("initbook_fopen");
		return;
	}
	fread(&(pb->d_max), sizeof(int), 1, pf);
	fread(&(pb->d_now), sizeof(int), 1, pf);
	peo* tmp = (peo*)realloc(pb->data,(pb->d_max) * sizeof(peo));
	if (tmp == NULL)
	{
		perror("initbook_realloc");
		return;
	}
	pb->data = tmp;
	fread(pb->data, sizeof(peo), pb->d_now, pf);
	fclose(pf);
	pf = NULL;

}
void Add(abook* pb)//���Ӻ���
{
	if (pb->d_max == pb->d_now)//��������Ƿ���
	{
		peo* tmp = (peo*)realloc(pb->data, (pb->d_max + 3) * sizeof(peo));//����3����
		if (tmp == NULL)
		{
			perror("Add");//��ӡ����
			return ;
		}
		pb->data = tmp;
		pb->d_max += 3;
	}
	else
	{
		printf("����������->:");
		scanf("%s", pb->data[pb->d_now].name);
		printf("�������ֻ�����->:");
		scanf("%s", pb->data[pb->d_now].pnumber);
		printf("�������ϵ->:");
		scanf("%s", pb->data[pb->d_now].relationship);
		printf("�������ַ->:");
		scanf("%s", pb->data[pb->d_now].adress);
		pb->d_now++;
	}
}
void printbook(abook* pb)//��ӡ�����˵���Ϣ
{
	printf("����      �ֻ�����        ��ϵ       ��ַ\n");
	for (int i = 0; i < pb->d_now; i++)
	{
		printf("%-10s", pb->data[i].name);
		printf("%-16s", pb->data[i].pnumber);
		printf("%-11s", pb->data[i].relationship);
		printf("%-30s", pb->data[i].adress);
		printf("\n");
	}
}
void Free(abook* pb)//�ͷſռ�
{
	free(pb->data);
	pb->data = NULL;
	pb->d_max = 0;
	pb->d_now = 0;
}
void Delete(abook* pb)//ɾ������
{
	printf("��������Ҫ���ҵ��˵�����->:");
	char arr[10] = { 0 };
	scanf("%s", arr);
	int tmp = Search_by_name(pb, arr);
	if (tmp != -1)
	{
		//�ѵ�i+2���ˣ��±�Ϊi+1������d_now������ǰ�ƶ�һλ���Ӷ��ﵽɾ����Ч��
		for (int j = tmp+1; j < pb->d_now; j++)
		{
			pb->data[j-1] = pb->data[j];
		}
		pb->d_now--;
		printf("ɾ���ɹ�\n");
		printbook(pb);
	}
	else
	{
		printf("�Ҳ�������\n");
		printf("ɾ��ʧ��\n");
	}
}
int Search_by_name(abook* pb, char* arr)//���Һ������ҵ�����i,iΪ(�ڼ�����-1)
{
	for (int i = 0; i < pb->d_now; i++)
	{
		if (strcmp(pb->data[i].name, arr) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Printsigle(int tmp, abook* pb)//��ӡ�����˵���Ϣ
{
	printf("����      �ֻ�����        ��ϵ       ��ַ\n");
	printf("%-10s", pb->data[tmp].name);
	printf("%-16s", pb->data[tmp].pnumber);
	printf("%-11s", pb->data[tmp].relationship);
	printf("%-30s", pb->data[tmp].adress);
	printf("\n");
}
void Revise(abook* pb, char* arr)
{
	int tmp = Search_by_name(pb, arr);
	if (tmp == -1)
	{
		printf("�����ڴ���\n");
	}
	else
	{
		printf("��������Ҫ�޸ĺ����Ϣ\n");
		printf("����������->:");
		scanf("%s", pb->data[tmp].name);
		printf("�������ֻ�����->:");
		scanf("%s", pb->data[tmp].pnumber);
		printf("�������ϵ->:");
		scanf("%s", pb->data[tmp].relationship);
		printf("�������ַ->:");
		scanf("%s", pb->data[tmp].adress);
	}
}
void storedata(abook* pb)
{
	FILE* pf = fopen("adress book.dat", "w");//�����ļ�����д�����ʽ��
	if (pf == NULL)
	{
		perror(fopen);
		return;
	}
	fwrite(&(pb->d_max), sizeof(int), 1, pf);
	fwrite(&(pb->d_now), sizeof(int), 1, pf);
	fwrite(pb->data, sizeof(peo), pb->d_now, pf);
	fclose(pf);
	pf = NULL;
}