#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//ʵ�ֶ�̬˳�������²�����
//
//// ��̬˳��� 
//struct SeqList
//{
//	DataType array[MAXSIZE]; // ����˳���������Ԫ�� 
//	int size; // ˳�������ЧԪ�صĸ��� 
//};
//*/
//
//typedef int DataType;
//
//typedef struct SeqList
//{
//	DataType* _array; // ����˳�������ЧԪ�ظ��� 
//	int _capacity; // �ռ��ܴ�С 
//	int _size; // ��ЧԪ�ظ��� 
//}SeqList, *PSeqList;
//
////typedef struct SeqList SeqList; 
//
//
//void SeqListInit(PSeqList ps);
//void SeqListDestroy(PSeqList ps);
//
//// β�� 
//void SeqListPushBack(PSeqList ps, DataType data);
//// βɾ 
//void SeqListPopBack(PSeqList ps);
//
//// ͷ�� 
//void SeqListPushFront(PSeqList ps, DataType data);
//// ͷɾ 
//void SeqListPopFront(PSeqList ps);
//
//// ����λ�ò��� 
//void SeqListInsert(PSeqList ps, int pos, DataType datda);
//
//// ����λ��ɾ�� 
//void SeqListErase(PSeqList ps, int pos);
//
//// ���data�ͷ���˳����� 
//int SeqListFind(PSeqList ps, DataType data);
//
//// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
//void SeqListRemove(PSeqList ps, DataType data);
//
//// �Ƴ�˳���������ֵΪdata��Ԫ�� 
//void SeqListRemoveAll(PSeqList ps, DataType data);
//
//// ��ȡ˳�����ЧԪ�ظ��� 
//int SeqListSize(PSeqList ps);
//
//// ��ȡ˳�������� 
//int SeqListCapacity(PSeqList ps);
//
//// ���˳����Ƿ�Ϊ�� 
//int SeqListEmpty(PSeqList ps);
//
//// ��ȡ˳����е�һ��Ԫ�� 
//DataType SeqListFront(PSeqList ps);
//
//// ��ȡ˳��������һ��Ԫ�� 
//DataType SeqListBack(PSeqList ps);
//////////////////////////////////////// 
//// 
//void PrintSeqList(PSeqList ps);

int main()
{
	SeqList con;
	SeqListInit(&con);
	
	SeqListPushBack(&con, 1);
	PrintSeqList(&con);
	SeqListPopBack(&con);
	SeqListPushFront(&con, 2);
	SeqListPopFront(&con);
	SeqListInsert(&con, 2, 3);
	SeqListErase(&con,2);
	SeqListFind(&con, 3);
	SeqListRemove(&con, 3);
	SeqListRemoveAll(&con, 3);
	SeqListSize(&con);
	SeqListCapacity(&con);
	SeqListEmpty(&con);
	SeqListBack(&con);
	PrintSeqList(&con);
	SeqListDestroy(&con);
	system("pause");
	return 0;
}