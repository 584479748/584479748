#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

//1.�Զ������Ͳ���֪ʶдһƪ���͡�
//֪ʶ�㣺
//>�ṹ�����ʹ���
//>�ṹ���ʼ��
//>�ṹ���ڴ����
//>λ�Σ�λ�μ������С��
//>ö�� + ���ϡ�
//
//2.ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//
//�ṩ������
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��




//�ύ��ҵ
void menu()
{
	printf("********************************\n");
	printf("******  0.EXIT     1.ADD  ******\n");
	printf("******  2.DEL      3.FIND ******\n");
	printf("******  4.XIUGAI   5.SHOW ******\n");
	printf("********************************\n");
}
//enum cotion
//{
//	EXIT,
//	ADD,
//	DEL,
//	FIND,
//	XIUGAI,
//	SHOW
//};
void test()
{
	int input = 0;
	contact con;//date sz capacity
	
	Inticontact(&con);
	do
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			SAVEcontact(&con);
			DROPcontact(&con);
			break;
		case 1:
			ADDcontact(&con);
			break;
		case 2:
			DELcontact(&con);
			break;
		case 3:
			FINDcontact1(&con);
			break;
		case 4:
			XIUGAIcontact(&con);
			break;
		case 5:
			SHOWcontact(&con);
			break;
		default:
			printf("��������������ѡ��>");
			scanf("%d", &input);
			break;
		}
	} while (input);
}
int main()
{

	test();
	system("pause");
	return 0;
}