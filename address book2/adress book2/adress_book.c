#define _CRT_SECURE_NO_WARNINGS 1
#include"adress_book.h"


void menu()//菜单
{
	//增加，删除，查询，修改操作，最好能排序
	printf("          通讯录             \n");
	printf("     1.增加     2.删除       \n");
	printf("     3.查询     4.修改       \n");
	printf("     5.排序   0.退出并保存   \n");
	printf("请选择->:");
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
	while(fread(&tmp, sizeof(peo), 1, pf) == 1)//tmp为读到的数据，tmp2为新开辟的内存，tmp3为寻找到尾部创建的临时变量
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
void Add(abook** ppb)//添加通讯录
{
	abook* tmp = (abook*)malloc(sizeof(abook));//开辟新内存tmp，再把数据放到tmp中。如果*ppb为空指针的话，就令*ppb = tmp,否则，找到链表的尾部再赋值
	if (tmp == NULL)
	{
		perror("Add_malloc");
		return;
	}
	tmp->next = NULL;
	printf("请输入姓名->:");
	scanf("%s", tmp->data.name);
	printf("请输入手机号码->:");
	scanf("%s", tmp->data.pnumber);
	printf("请输入关系->:");
	scanf("%s", tmp->data.relationship);
	printf("请输入地址->:");
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
	//存储通讯录
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
	printf("姓名      手机号码        关系       地址\n");
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
	//找人
	char arr[10] = { 0 };
	printf("请输入你要删除的人->:");
	scanf("%s", arr);
	abook* tmp = *pb;//遍历
	abook* tmp2 = NULL;//记录tmp的前一个值
	abook* tmp3 = NULL;//临时存放next
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
			printf("删除成功\n");
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}
	if (tmp == NULL)
	{
		printf("此人不存在\n");
	}
}
void Search(abook* pb)
{
	printf("请输入你要查找的人的名字->:");
	char arr[10] = { 0 };
	scanf("%s", arr);
	while (pb != NULL)
	{
		if (strcmp(arr, pb->data.name) == 0)
		{
			printf("姓名      手机号码        关系       地址\n");
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
		printf("此人不存在\n");
	}
}
void Revise(abook** pb)
{
	//查找
	printf("请输入被修改人的名字->:");
	char arr[10] = { 0 };
	scanf("%s", arr);
	abook* tmp = *pb;//tmp用来遍历整个链表
	while (tmp != NULL)
	{
		if (strcmp(arr, tmp->data.name) == 0)
		{
			//修改
			printf("请输入姓名->:");
			scanf("%s", tmp->data.name);
			printf("请输入手机号码->:");
			scanf("%s", tmp->data.pnumber);
			printf("请输入关系->:");
			scanf("%s", tmp->data.relationship);
			printf("请输入地址->:");
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
		printf("不存在此人\n");
	}
	
}