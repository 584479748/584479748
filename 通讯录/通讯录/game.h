#ifndef _GAME__H_
#define _GAME__H_


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct people
{
	char name[10];
	int age;
	char sex[4];
	char addre[20];
	char tele[12];
}people;

typedef struct contact
{
	people *date;//�����Ϣ
	int sz;//��ǰ��Ч��Ϣ����
	int capacity;//����
}contact;

void Inticontact(contact *pc);
void ADDcontact(contact *pc);
void SHOWcontact(contact *pc);
void FINDcontact1(contact *pc);
void XIUGAIcontact(contact *pc);
void DELcontact(contact *pc);
void DROPcontact(contact *pc);
void SAVEcontact(contact *pc);
void LOADcontact(contact *pc);

#endif //GAME__H_