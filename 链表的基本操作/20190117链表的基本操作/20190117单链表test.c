#define _CRT_SECURE_NO_WARNINGS


#include "SList.h"


//1. ��Ϥ����Ľṹ
//2. ��Ϥ��ͷ�����벻��ͷ���������
//3. �����ͷ����������²�����
//����ͷ�ڵ�ĵ����� 
//typedef int SDataType;

// �ڵ�ṹ 
//typedef struct SListNode
//{
//	SDataType _data;
//	struct SListNode* _pNext;
//}Node;


// ��һ������ṹ 
//typedef struct SList
//{
//	Node* _pHead;
//}SList;
//
//
//// ����ĳ�ʼ�� 
//void SListInit(SList* pl);
//
//// ��������β��ֵΪdata�Ľڵ� 
//void SListPushBack(SList* pl, SDataType data);
//
//// ɾ���������һ���ڵ� 
//void SListPopBack(SList* pl);
//
//// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
//void SListPushFront(SList* pl, SDataType data);
//
//// ɾ�������е�һ���ڵ� 
//void SListPopFront(SList* pl);
//
//// ������posλ�ú������Ϊdata�Ľڵ� 
//void SListInsertAfter(Node* pos, SDataType data);
//
//// ɾ��������ֵΪdata�Ľڵ� 
//void SListErase(SList* pl, Node* pos);
//
//// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
//Node* SListFind(SList* pl, SDataType data);
//
//// �������� 
//void SListDestroy(SList* pl);
//
//// ��ȡ��������Ч�ڵ�ĸ��� 
//int SListSize(SList* pl);
//
//// ��������Ƿ�Ϊ�� 
//int SListEmpty(SList* pl);
//// ��ȡ����ĵ�һ���ڵ� 
//Node* SListFront(SList* pl);
//
//// ��ȡ����ĵڶ����ڵ� 
//Node* SListBack(SList* pl);
//
//void SListRemove(SList* pl, SDataType data);
//void SListRemoveAll(SList* pl, SDataType data);

void test1()
{
	SList con;
	SListInit(&con);
	SListPushBack(&con, 1);
	SListPushBack(&con, 2);
	SListPushBack(&con, 3);
	SListPushBack(&con, 4);
	SListPushBack(&con, 5);
	SListPushBack(&con, 6);
	PrintList(&con);
	SListPushFront(&con, 2);
	SListPushFront(&con, 2);
	SListPushFront(&con, 2);
	SListPushFront(&con, 2);
	PrintList(&con);
	SListPopFront(&con);
	PrintList(&con);
	Node*ret = SListFind(&con, 2);
	SListInsertAfter(&con,ret , 6);
	PrintList(&con);
	SListErase(&con, ret);
	PrintList(&con);
	printf("%d \n", SListSize(&con));
	int a = SListEmpty(&con);
	if (a == 1)
		printf("����Ϊ�գ�>\n");
	else
		printf("����Ϊ�գ�>\n");
	SListRemove(&con, 6);
	PrintList(&con);
	SListRemoveAll(&con, 2);
	PrintList(&con);
	SListDestroy(&con);
}
int main()
{
	
	test1();
	system("pause");
	return 0;
}