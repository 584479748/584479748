#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("**************************\n");
	printf("*****1.play   2.exit *****\n");
	printf("**************************\n");
}
void game()
{
	int i = 0;
	int j = 0;
	i = rand() % 100;
	printf("��������²������>");
	scanf("%d", &j);
	while (1)

	{
		if (j > i)
		{
			printf("��ֵ�ϴ�����������");
			scanf("%d", &j);
		}
		else if (j < i)
		{
			printf("��ֵ��С������������");
			scanf("%d", &j);
		}
		else
			break;
	}
	printf("��ϲ��¶���");
	printf("%d", j);
}
int main()
{
	int j = 0;
	menu();
	srand((unsigned int)time(NULL));
	printf("��ѡ��>");
	scanf("%d", &j);
	switch (j)
	{
	case 0:
		printf("��Ϸ������>");
		break;
	case 1:
		game();
	default:
		printf("�����������������룺>");
		scanf("%d", &j);
	}
	system("pause");

	return 0;
}