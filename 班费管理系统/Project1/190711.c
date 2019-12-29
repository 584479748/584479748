#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma pack(1)
const char *DataFilename = "d:\\classfee.data";
typedef struct classfee ClassFee;
struct classfee{
	int id;
	char io;
	char cbr[10];
	char reason[256];
	float fee;
	char memo[256];
	float restfee;
	ClassFee *next;
};
void ShowMenu() {
	const char *menu = {
		"1.��Ӱ����֧��Ϣ\n"
		"2.������а����֧��Ϣ\n"
		"3.��ѯ�����֧��Ϣ\n"
		"4.�޸İ����֧��Ϣ\n"
		"5.�˳�\n��ѡ��\n"
	};
	printf("%s", menu);
}
ClassFee *fee;
int index = 0;
float lastfee = 0.0f;
int InitDataFile() {
	FILE *fp = fopen("DataFilename", "rb");
	size_t sizefee = sizeof(ClassFee);
	fee = (ClassFee*)malloc(sizefee);
	fee->next = NULL;
	if (fp == NULL) {
		return 1;
	}
	ClassFee *p = fee;
	size_t len;
	while (!feof(fp)) {
		ClassFee *q = (ClassFee*)malloc(sizefee);
		len = fread((char*)q, sizefee, 1, fp);
		if (len == 1) {
			index++;
			lastfee = q->restfee; //���һ��ȡ������Ϊ������
			q->next = NULL;
			p->next = q;
			p = q;
		}
	}
	fclose(fp);
	return 0;
}
int WriteDataFile() {
	FILE *fp = fopen("DataFilename", "wb");
	if (fp == NULL) {
		printf("�޷��������ļ���%s,���顣\n", DataFilename);
		return 1;
	}
	size_t sizefee = sizeof(ClassFee);
	ClassFee *p = fee->next;
	while (p) {
		fwrite((char *)p, sizefee, 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 0;
}
void FreeResource() {
	ClassFee *p = fee, *q = NULL;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
}
void AppendFee(ClassFee *f) {
	ClassFee *p = fee, *q;
	q = p->next;
	while (q) {
		p = q;
		q = p->next;
	}
	p->next = f;
}
void InputFee() {
	ClassFee *p = (ClassFee*)malloc(sizeof(ClassFee));
	p->id = ++index;
	fflush(stdin);
	printf("���������Ϣ��\n");
	printf("  ֧��(o)?����(i)?��");
	scanf("%c", &p->io);
	if (p->io != 'i' && p->io != 'o') {
		printf("������󣬰����봦���˴�Ӧ������ѭ�����룬ֱ������ɹ�Ϊֹ������ʡ��\n");
		p->io = 'i';
	}
	printf("  �����ˣ�"); scanf("%s", p->cbr);
	printf("  ԭ��"); scanf("%s", p->reason);
	printf("  ��"); scanf("%f", &p->fee);
	printf("  ��ע��"); scanf("%s", p->memo);
	p->restfee = p->io == 'i' ? (lastfee + p->fee) : (lastfee - p->fee);
	lastfee = p->restfee;
	p->next = NULL;
	AppendFee(p);
	printf("-------------------------------------------------\n");
}
void DisplayFee(ClassFee *p) {
	printf("  ��֧��� :   %d\n", p->id);
	printf("  ����/֧��:   %s\n", p->io == 'i' ? "����" : "֧��");
	printf("  ������   :   %s\n", p->cbr);
	printf("  ԭ��     :   %s\n", p->reason);
	printf("  ���     :   %.2f\n", p->fee);
	printf("  ��ע     :   %.2f\n", p->memo);
	printf("  ���     :   %.2f\n", p->restfee);
	printf("-------------------------------------------------\n");
}
void Search() {
	int s;
	const char *msg[] = { "������֧��ţ�", "����ԭ��" };
	printf("�����ѯ������\n��1.����֧��Ų�ѯ\n��2.��ԭ���ѯ:");
	fflush(stdin);
	scanf("%d", &s);
	ClassFee *p = fee->next;
	if (s == 1) {
		size_t s0;
		printf("%s", msg[s - 1]);
		scanf("%d", &s0);
		while (p) {
			if (p->id == s0) {
				DisplayFee(p);
				break;
			}
			p = p->next;
		}
	}
	else if (s == 2) {
		char r[256];
		printf("%s", msg[s - 1]);
		scanf("%s", r);
		while (p) {
			if (strstr(p->reason, r) != NULL) {
				DisplayFee(p);
			}
			p = p->next;
		}
	}
}
void ModifyFee() {
	size_t s;
	printf("������֧��ţ�");
	scanf("%d", &s);
	ClassFee *p = fee->next;
	while (p) {
		if (p->id == s) {
			DisplayFee(p);
			printf("�����޸���Ϣ��\n-------------------------------\n");
			//�����p�����޸ģ�����Ƚ��鷳�����������޸ı��ڵ����Ϣ
			//�����fee������/֧�������޸ģ�����Ҫ�޸ĺ������нڵ��restfee����Ϣ
			//�е��鷳������д�ˣ����Լ�������鼴�ɡ�
			break;
		}
		p = p->next;
	}
}
int main() {
	int choice;
	InitDataFile();
	printf("index=%d, lastfee=%.2f\n", index, lastfee);
	while (1) {
		ShowMenu();
		scanf("%d", &choice);
		if (choice<1 || choice>5) {
			system("cls");
			printf("��������������������\n------------------------\n");
			continue;
		}
		else {
			if (choice == 5) {
				WriteDataFile();
				break;
			}
			else if (choice == 1) {
				InputFee();
			}
			else if (choice == 2) {
				system("cls");
				ClassFee *p = fee->next;
				while (p) {
					DisplayFee(p);
					p = p->next;
				}
			}
			else if (choice == 3) {
				Search();
			}
			else if (choice == 4) {
				ModifyFee();
			}
		}
	}
	return 0;
}