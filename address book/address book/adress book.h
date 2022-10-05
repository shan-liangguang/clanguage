#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct people//一个人的基本信息
{
	char name[10];
	int pnumber[12];
	char relationship[10];
	char adress[30];
}peo;
struct adress_book
{
	peo* data;


};

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