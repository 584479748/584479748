#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

////1.ʵ��һ�����������������ַ����е�k���ַ���
////ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ��õ�CDAB
////
//
//
//char *stmy_ing(char arr[5], int  k,int sz)
//{
//	int temp = 0;
//	char *p = arr;
//	while (k)
//	{
//		for (int i = 0; i < sz - 2; i++)
//		{
//			temp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = temp;
//		}
//		k--;
//	}
//	return p;
//}
//int main()
//{
//	char arr[5] = "ABCD";
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	printf("%s", stmy_ing(arr, k,sz));
//	system("pause");
//	return 0;
//}
////2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
////���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
////
////AABCD����һ���ַ��õ�ABCDA
////AABCD���������ַ��õ�BCDAA
////
////AABCD����һ���ַ��õ�DAABC
////
////�ύ��ҵ

int main()
{
	char arr[15] = "AABCD";
	const char *s2 = "BCDAA";
	int len = strlen(s2);
	arr[15] = strncat(arr, arr,len);
	char* ret = strstr(arr, s2);
	if (*ret!=NULL)
	{
		printf("�ǣ�");
	}
	else 
	printf("���ǣ�");
	system("pause");
	return 0;
}