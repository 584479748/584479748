#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//

//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 5;
//	int j = 0;
//	for (j = 0; j < 32; j++)
//	{
//		i = i + ((value >> j) & 1)*pow(2, 31 - j);
//	}
//	return i;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", reverse_bit(n));
//	system("pause");
//	return 0;
//}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

//int reverse_bit(int a, int b)
//{
//	return a&b + ((a^b) >> 1);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d", reverse_bit(a, b));
//	system("pause");
//	return 0;
//}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩


//int here(int *arr, int sz)
//{
//	int n = *arr;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		n ^= (*arr);
//	}
//	return n;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d", here(arr, sz));
//	system("pause");
//}
//4.
//��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//
//
//			�ύ��ҵ

int Srlen(char *q)
{
	int count = 0;
	while ((*q!='\0')&&(*q!=' '))
	{
		count++;
		q++;
	}
	return count;
}
int Strlen(char *arr)
{
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}
void Reverse_bit(char  *arr, int  sz)
{
	char* left = arr;
	char* right = arr + (sz - 1);
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = *left;
		right--;
		left++;
	}
}
void reverse_bit(char *arr, int  sz)
{
	//�������ַ���ת
	Reverse_bit(arr, sz);
	//��ÿ�����ʷ�ת"student a am i"
	while (arr)
	{
		char* q = arr;
		while ((*arr!=' ')&&(*arr!='\0'))
		{
			 *q++=*arr++;

		}
		int len = Srlen(q);
		Reverse_bit(q, len);
		int i = 0;
		printf("%s", q);
		if (*arr != '\0')
		{
			arr++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	char sz = Strlen(arr);
	reverse_bit(arr, sz);
	system("pause");
	return 0;
}