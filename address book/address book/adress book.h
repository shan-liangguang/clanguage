#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct people//一个人的基本信息
{
	char name[10];
	char pnumber[12];
	char relationship[10];
	char adress[30];
}peo;
typedef struct adress_book
{
	peo* data;
	int d_max;//data最大容量
	int d_now;//data现在已使用的容量（方便后面打印通讯录）
}abook;

enum
{
	exit,
	add,
	delete,
	search,
	revise,
	sort
};
void menu();
void initbook(abook*pb);
void Add(abook* pb);
void printbook(abook* pb);
void Free(abook* pb);
void Delete(abook* pb);
int Search_by_name(abook* pb, char* arr);
void Printsigle(int tmp, abook* pb);
void Revise(abook* pb, char* arr);