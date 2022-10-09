#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum
{
	Exit,
	add,
	delete,
	search,
	revise,
	sort
};
typedef struct people//一个人的基本信息
{
	char name[10];
	char pnumber[12];
	char relationship[10];
	char adress[30];
}peo;
typedef struct adress_book
{
	peo data;
	struct adress_book* next;
}abook;
void menu();
void initbook(abook** ppb);
void Add(abook** ppb);
void storebook(abook* pb);
void Printbook(abook* pb);
void Delete(abook** pb);
void Serach(abook* pb);
void Revise(abook** pb);