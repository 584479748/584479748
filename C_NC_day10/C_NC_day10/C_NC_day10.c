//1.
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
	// ���� 1��λ�� 
//}

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((value >> i) && 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", count_one_bits(n));
//	system("pause");
//	return 0;
//}
//2.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�

//void count_one_bits(const int n)
//{
//	int i = 0;
//	printf("ż������\n");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", ((n >> i) & 1));
//	}
//	printf("\n");
//	printf("��������\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", ((n >> i) & 1));
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	count_one_bits(n);
//	system("pause");
//	return 0;
//}
//3. ���һ��������ÿһλ��
//void count_one_bits(int n)
//{
//	if (n >= 10)
//	count_one_bits(n / 10);
//	printf("%d", n % 10);
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	count_one_bits(n);
//	system("pause");
//	return 0;
//}
//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7

int count_one_bits(int i, int  j)
{
	int count = 0;
	int n = i^j;
	while ( n != 0 )
	{
		n &=(n-1);
		count++;
	}
	return count;

}
int main()
{
	int i = 1999;
	int j = 2299;
	printf("%d", count_one_bits(i, j));
	system("pause");
	return 0;
}
//	   5.д�����ܽ�C���Բ��������������ӷ����ң�������Ⱥ�