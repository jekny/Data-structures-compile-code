//c���Գ�ʼ��˳���
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

int InitList(sqList* L)//���ݵ��ǵ�ַ��������ָ��������
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
	InitList(&L);//�� C �����У��������Ҫ�����ܹ��޸ĺ����ⲿ����ı�����ֵ�������ͨ��ָ����������������ĵ�ַ�������Ϊʲô�� C �����е��� InitList ʱ��Ҫ���� &L ��ԭ��
	return 0;
}
*/

//c++�г�ʼ��˳���
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

int InitList(sqList& L)//�����&�����ã��ں����ڲ��Ա�Ĳ�����ֱ�Ӹı����
{
	L.data = new student;
	if (L.data == nullptr)//nullptr��NULL�ȼۣ�ֻ��c++����
	{
		exit(-1);//�˳�������
	}
	L.length = 0;
	return 0;
}
int main()
{
	InitList(L);//��c++�е��ó�ʶ������ʱ��ֱ�Ӵ�L��ȥ�ģ���c���Բ�ͬ
				//c++��Ҳ������InitList��&L��������int InitList(sqList *L)�����������ǲ���ȫ
	return 0;
}


