#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

// ����ĳ�ʼ�� 
void SListInit(SList* pl)
{
	assert(pl);
	
	pl->_pHead = NULL;
}


Node* BuyListNode(SDataType data)
{
	Node* PNode = (Node*)malloc(sizeof(Node));
	if (NULL == PNode)
	{
		perror("use malloc");
		return NULL;
	}
	PNode->_data = data;
	PNode->_pNext = NULL;
	return PNode;
}
// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, SDataType data)
{
	Node *Pcur = NULL;
	assert(pl);

	if (pl->_pHead == NULL)
	{
		pl->_pHead = BuyListNode(data);
	}
	else
	{
		Pcur = pl->_pHead;
		while (Pcur->_pNext)
		{
			Pcur = Pcur->_pNext;
		}
		Pcur->_pNext = BuyListNode(data);
	}

}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl)
{
	Node* Pcur = NULL;
	assert(pl);
	Pcur = pl->_pHead;
	if (pl->_pHead == NULL)
	{
		return;
	}
	if (pl->_pHead->_pNext == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else
	{
		while (pl->_pHead->_pNext->_pNext)
		{
			Pcur = Pcur->_pNext;
		}
		free(Pcur->_pNext);
		Pcur->_pNext = NULL;
	}
}

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	Node*NewData = NULL;
	assert(pl);
	NewData = BuyListNode(data);
	NewData->_pNext = pl->_pHead;
	pl->_pHead = NewData;
}

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl)
{
	Node* Pcur = NULL;
	assert(pl);
	if(NULL == pl->_pHead)
	{
		return;
	}
	else
	{
		Pcur = pl->_pHead;
		pl->_pHead = Pcur->_pNext;
		free(Pcur);
		Pcur = NULL;
	}
}


// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(SList* pl,Node* pos, SDataType data)
{
	Node*NewData = BuyListNode(data);
	Node* Pcur = NULL;
	assert(pl);
	assert(pos);
	if (pos == NULL)
	{
		return;
	}
	Pcur = pos->_pNext;

	pos->_pNext = NewData;
	pos->_pNext->_pNext = Pcur;
}

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos)
{
	Node *pcur = NULL;
	assert(pl);
	assert(pos);
	if (pl->_pHead == NULL || pos == NULL)
	{
		return;
	}
	if (pos == pl->_pHead)
	{
		pl->_pHead = pos->_pNext;
		free(pos);
		pos = NULL;
		return;
	}
	pcur = pl->_pHead;
	while (pcur->_pNext != pos)
	{
		pcur = pcur->_pNext;
	}
	pcur->_pNext = pos->_pNext;
	free(pos);
	pos = NULL;
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data)
{
	Node * cur = NULL;
	assert(pl);
	cur = pl->_pHead;
	while (cur->_data != data &&cur != NULL)
	{
		cur = cur->_pNext;
	}
	return cur;
}

// �������� 
void SListDestroy(SList* pl)
{
	Node *pcur = NULL;
	assert(pl);
	pcur = pl->_pHead;
	while (pcur)
	{
		pl->_pHead = pcur->_pNext;
		free(pcur);
		pcur = pl->_pHead;
	}
	pl->_pHead = NULL;
}

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl)
{
	Node *pcur = NULL;
	assert(pl);
	int count = 0;
	while (pcur)
	{
		count++;
		pcur = pcur->_pNext;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	assert(pl);
	if (NULL!= pl->_pHead) 
	{
		return 1;
	}
	return 0;
}

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->_pHead;
}

// ��ȡ��������һ���ڵ� 
Node* SListBack(SList* pl)
{
	Node* pcur = NULL;
	assert(pl);
	pcur = pl->_pHead;
	while (pcur->_pNext)
	{
		pcur = pcur->_pNext;
	}
	return pcur;
}

void SListRemove(SList* pl, SDataType data)
{
	assert(pl);
	if (pl == NULL)
	{
		printf("����Ϊ�գ�>");
	}
	Node *ret = SListFind( pl,  data);
	if (NULL == ret)
	{
		return;
	}
	SListErase(pl,ret);
}
void SListRemoveAll(SList* pl, SDataType data)
{
	Node* pcur = NULL;
	Node *next = NULL;
	assert(pl);
	if (pl == NULL)
	{
		printf("����Ϊ�գ�>");
	}
	next = pl->_pHead;
	while (next->_pNext)
	{
		if (next->_pNext->_data == data)
		{
			pcur = next->_pNext;
			next->_pNext = next->_pNext->_pNext;
			free(pcur);
			continue;
		}
		next = next->_pNext;
	}
	if (pl->_pHead->_data == data)
	{
		pcur = pl->_pHead;
		pl->_pHead = pcur->_pNext;
		free(pcur);
	}
	if (next->_data == data)
	{
		SListPopBack(pl);
	}
}

void PrintList(SList* pl)
{
	Node *pcur = NULL;
	assert(pl);
	pcur = pl->_pHead;
	while (pcur)
	{
		printf("%d---> ", pcur->_data);
		pcur = pcur->_pNext;
	}
	printf("NULL\n");
}


