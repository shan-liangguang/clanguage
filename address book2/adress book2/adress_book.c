#define _CRT_SECURE_NO_WARNINGS 1
#include"adress_book.h"


void menu()//�˵�
{
	//���ӣ�ɾ������ѯ���޸Ĳ��������������
	printf("          ͨѶ¼             \n");
	printf("     1.����     2.ɾ��       \n");
	printf("     3.��ѯ     4.�޸�       \n");
	printf("     5.����   0.�˳�������   \n");
	printf("��ѡ��->:");
}
void initbook(abook** ppb)
{
	FILE*pf = fopen("adress_book.dat", "r");
	if (pf == NULL)
	{
		perror("initbook_fopen");
		return;
	}
	peo tmp = {0};
	while(fread(&tmp, sizeof(peo), 1, pf) == 1)//tmpΪ���������ݣ�tmp2Ϊ�¿��ٵ��ڴ棬tmp3ΪѰ�ҵ�β����������ʱ����
	{
		abook* tmp2 = (abook*)malloc(sizeof(abook));
		if (tmp2 == NULL)
		{
			perror("initbook_realloc");
			return;
		}
		tmp2->data = tmp;
		tmp2->next = NULL;
		if (*ppb == NULL)
		{
			*ppb = tmp2;
		}
		else
		{
			abook* tmp3 = *ppb;
			while (tmp3->next != NULL)
			{
				tmp3 = tmp3->next;
			}
			tmp3->next = tmp2;
		}
	}
	fclose(pf);
	pf = NULL;

}
void Add(abook** ppb)//���ͨѶ¼
{
	abook* tmp = (abook*)malloc(sizeof(abook));//�������ڴ�tmp���ٰ����ݷŵ�tmp�С����*ppbΪ��ָ��Ļ�������*ppb = tmp,�����ҵ������β���ٸ�ֵ
	if (tmp == NULL)
	{
		perror("Add_malloc");
		return;
	}
	tmp->next = NULL;
	printf("����������->:");
	scanf("%s", tmp->data.name);
	printf("�������ֻ�����->:");
	scanf("%s", tmp->data.pnumber);
	printf("�������ϵ->:");
	scanf("%s", tmp->data.relationship);
	printf("�������ַ->:");
	scanf("%s", tmp->data.adress);
	if (*ppb == NULL)
	{
		*ppb = tmp;
		
	}
	else
	{
		abook* tmp2 = *ppb;
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp;
	}
	
}
void storebook(abook* pb)
{
	FILE* pf = fopen("adress_book.dat", "w");
	if (pf == NULL)
	{
		perror("storebook fpoen");
		return;
	}
	//�洢ͨѶ¼
	abook *tmp = pb;
	while (tmp != NULL)
	{
		fwrite(&(tmp->data), sizeof(peo), 1, pf);
		tmp = tmp->next;
	}
	fclose(pf);
	pf = NULL;
	
}
void Printbook(abook* pb)
{
	printf("����      �ֻ�����        ��ϵ       ��ַ\n");
	while (pb != NULL)
	{
		
		printf("%-10s", pb->data.name);
		printf("%-16s", pb->data.pnumber);
		printf("%-11s", pb->data.relationship);
		printf("%-30s", pb->data.adress);
		printf("\n");
		pb = pb->next;
	}
}
void Delete(abook** pb)
{
	//����
	char arr[10] = { 0 };
	printf("��������Ҫɾ������->:");
	scanf("%s", arr);
	abook* tmp = *pb;//����
	abook* tmp2 = NULL;//��¼tmp��ǰһ��ֵ
	abook* tmp3 = NULL;//��ʱ���next
	while (tmp != NULL)
	{
		if (strcmp(arr, tmp->data.name) == 0)
		{
			
			tmp3 = tmp->next;
			free(tmp);
			if (tmp == *pb)
			{
				*pb = tmp3;
				break;
			}
			else
			{
				tmp2->next = tmp3;
				break;
				
			}
			printf("ɾ���ɹ�\n");
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}
	if (tmp == NULL)
	{
		printf("���˲�����\n");
	}
}
void Search(abook* pb)
{
	printf("��������Ҫ���ҵ��˵�����->:");
	char arr[10] = { 0 };
	scanf("%s", arr);
	while (pb != NULL)
	{
		if (strcmp(arr, pb->data.name) == 0)
		{
			printf("����      �ֻ�����        ��ϵ       ��ַ\n");
			printf("%-10s", pb->data.name);
			printf("%-16s", pb->data.pnumber);
			printf("%-11s", pb->data.relationship);
			printf("%-30s", pb->data.adress);
			printf("\n");
			break;
		}
		else
		{
			pb = pb->next;
		}
	}
	if (pb == NULL)
	{
		printf("���˲�����\n");
	}
}
void Revise(abook** pb)
{
	//����
	printf("�����뱻�޸��˵�����->:");
	char arr[10] = { 0 };
	scanf("%s", arr);
	abook* tmp = *pb;//tmp����������������
	while (tmp != NULL)
	{
		if (strcmp(arr, tmp->data.name) == 0)
		{
			//�޸�
			printf("����������->:");
			scanf("%s", tmp->data.name);
			printf("�������ֻ�����->:");
			scanf("%s", tmp->data.pnumber);
			printf("�������ϵ->:");
			scanf("%s", tmp->data.relationship);
			printf("�������ַ->:");
			scanf("%s", tmp->data.adress);
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	if (tmp == NULL)
	{
		printf("�����ڴ���\n");
	}
	
}