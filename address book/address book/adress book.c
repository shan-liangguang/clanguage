#define _CRT_SECURE_NO_WARNINGS 1
#include "adress book.h"
void menu()//菜单
{
	//增加，删除，查询，修改操作，最好能排序
	printf("          通讯录             \n");
	printf("     1.增加     2.删除       \n");
	printf("     3.查询     4.修改       \n");
	printf("     5.排序     0.退出       \n");
	printf("请选择->:");
}
void initbook(abook* pb)//初始化通讯录和读取文件信息
{
	pb->data = (peo*)malloc(5 * sizeof(peo));//一开始申请可以容纳5个人信息的空间
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
void Add(abook* pb)//增加函数
{
	if (pb->d_max == pb->d_now)//检查容量是否够用
	{
		peo* tmp = (peo*)realloc(pb->data, (pb->d_max + 3) * sizeof(peo));//增加3个人
		if (tmp == NULL)
		{
			perror("Add");//打印错误
			return ;
		}
		pb->data = tmp;
		pb->d_max += 3;
	}
	else
	{
		printf("请输入姓名->:");
		scanf("%s", pb->data[pb->d_now].name);
		printf("请输入手机号码->:");
		scanf("%s", pb->data[pb->d_now].pnumber);
		printf("请输入关系->:");
		scanf("%s", pb->data[pb->d_now].relationship);
		printf("请输入地址->:");
		scanf("%s", pb->data[pb->d_now].adress);
		pb->d_now++;
	}
}
void printbook(abook* pb)//打印所有人的信息
{
	printf("姓名      手机号码        关系       地址\n");
	for (int i = 0; i < pb->d_now; i++)
	{
		printf("%-10s", pb->data[i].name);
		printf("%-16s", pb->data[i].pnumber);
		printf("%-11s", pb->data[i].relationship);
		printf("%-30s", pb->data[i].adress);
		printf("\n");
	}
}
void Free(abook* pb)//释放空间
{
	free(pb->data);
	pb->data = NULL;
	pb->d_max = 0;
	pb->d_now = 0;
}
void Delete(abook* pb)//删除函数
{
	printf("请输入你要查找的人的名字->:");
	char arr[10] = { 0 };
	scanf("%s", arr);
	int tmp = Search_by_name(pb, arr);
	if (tmp != -1)
	{
		//把第i+2个人（下标为i+1）到第d_now个人向前移动一位，从而达到删除的效果
		for (int j = tmp+1; j < pb->d_now; j++)
		{
			pb->data[j-1] = pb->data[j];
		}
		pb->d_now--;
		printf("删除成功\n");
		printbook(pb);
	}
	else
	{
		printf("找不到此人\n");
		printf("删除失败\n");
	}
}
int Search_by_name(abook* pb, char* arr)//查找函数，找到返回i,i为(第几个人-1)
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
void Printsigle(int tmp, abook* pb)//打印单个人的信息
{
	printf("姓名      手机号码        关系       地址\n");
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
		printf("不存在此人\n");
	}
	else
	{
		printf("请输入你要修改后的信息\n");
		printf("请输入姓名->:");
		scanf("%s", pb->data[tmp].name);
		printf("请输入手机号码->:");
		scanf("%s", pb->data[tmp].pnumber);
		printf("请输入关系->:");
		scanf("%s", pb->data[tmp].relationship);
		printf("请输入地址->:");
		scanf("%s", pb->data[tmp].adress);
	}
}
void storedata(abook* pb)
{
	FILE* pf = fopen("adress book.dat", "w");//创建文件并以写入的形式打开
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