#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
//
//

//int main()
//{
//	int arr[11] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num1 = 0;
//	int num2 = 0;
//	int temp = 0;
//	int i = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		temp ^= arr[i];
//	}
//	for ( i = 0; i < 32; i++)
//	{
//		if (((temp >> i) & 1) == 1)
//		{
//			break;
//		}
//	}
//	int pos = i;
//	for (int i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			num1 ^= arr[i];
//		}
//	}
//	num2 = temp^num1;
//	printf("%d %d", num1, num2);
//	system("pause");
//	return 0;
//}
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
//
//int main()
//{
//	int money = 0;
//	int empty = money;
//	int hele = 0;	
//	scanf("%d", &money);
//	hele = 2 * money - 1;
//	printf("%d", hele);
//	system("pause");
//	return 0;
//}
//3.ģ��ʵ��strcpy

//char *my_strcpy(char *arr, char *arr1)
//{
//	char *count = arr;
//	while (*arr1)
//	{
//		*arr++ = *arr1++;
//	}
//	return count;
//}
//int main()
//{
//
//	char arr[20] = "abcdef";
//	char arr1[12] = "aaaaaaaaaa";
//	printf("%s\n", strcpy(arr, arr1));
//	printf("%s\n", my_strcpy(arr, arr1));
//	system("pause");
//	return 0;
//}
//4.ģ��ʵ��strcat


char *my_strcat(char *arr, char *arr1)
{
	char *count = arr;
	while (*arr++)
	{

	}
	while (*arr1)
	{
		(*arr++) = (*arr1++);
	}
	return count;
}

int main()
{
	char arr[10] = "abc";
	char arr1[4] = "def";
	printf("%s\n", strcat(arr, arr1));
	printf("%s\n", my_strcat(arr, arr1));
	system("pause");
	return 0;
}
