//c语言初始化顺序表
/*
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct sd
{
	int age;
	char name[10];
}student;
typedef struct sq
{
	student *data;
	int length;
}sqList;
sqList L;

int InitList(sqList* L)//传递的是地址，所以用指针来接收
{
	L->data = (student*)malloc(sizeof(student) * MAXSIZE);
	if (L->data == NULL)
	{
		exit(-1);
	}
	L->length = 0;
	return 0;
}
int main()
{
	InitList(&L);//在 C 语言中，如果你想要函数能够修改函数外部定义的变量的值，你必须通过指针来传递这个变量的地址。这就是为什么在 C 语言中调用 InitList 时需要传递 &L 的原因。
	return 0;
}
*/

//c++中初始化顺序表
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSIZE 100

typedef struct sd
{
	int age;
	char name[10];
}student;
typedef struct sq
{
	student* data;
	int length;
}sqList;
sqList L;

int InitList(sqList& L)//这里的&是引用，在函数内部对表的操作会直接改变表本身；
{
	L.data = new student;
	if (L.data == nullptr)//nullptr与NULL等价，只是c++中用
	{
		exit(-1);//退出程序函数
	}
	L.length = 0;
	return 0;
}
int main()
{
	InitList(L);//在c++中调用初识化函数时是直接传L过去的，与c语言不同
				//c++中也可以用InitList（&L）传递配int InitList(sqList *L)来操作，但是不安全
	return 0;
}


