//c语言初始化顺序表
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100  //注意宏定义后面不加分号
typedef struct sd
{
	int age;
	char name[10];
}student;
typedef struct sq
{
	student *data;//基地址（首地址）
	int length;   //记录表的长度（即元素个数）
}sqList;
sqList L;//创建一个sqList类型的叫L的顺序表
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


//c++中初始化顺序表
#define _CRT_SECURE_NO_WARNINGS 1（VS中的）
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
{			      //这里new一块空间也有说法：对顺序表（sqList）的初始化只需要为 student 类型的数组分配内存，而不是为整个 sqList 结构体数组分配内存，因为我们顺序表中的
			      //内容只包括age，name。我们都把它们放到了类型为student* 的data中，所以我们new一块空间只需要new student[MAXSIZE]的空间。length 成员是 sqList 结构体的一部分，它存储在栈上（如果
			      //sqList 是在函数内部定义的局部变量的话）或者全局/静态存储区（如果 sqList 是全局变量或静态变量的话）。因此，length 不需要额外分配内存，它已经和 sqList 结构体的其他成员一起被分配了
	L.data = new student[MAXSIZE]; //new一块空间
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


