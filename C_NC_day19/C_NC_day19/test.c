#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//1.ģ��ʵ��strncpy  ��������������


//char *my_strncpy(char *s1, char *s2, int k)
//{
//	char *ret = s1;
//	while (k)
//	{
//		*s1++ = *s2++;
//		k--;
//	}
//	return ret;
//}
//int main()
//{
//	char s1[10] = "abcdef";
//	printf("%s\n", strncpy(s1, s1 + 1, 1));
//	printf("%s\n", my_strncpy(s1, s1 + 1, 1));
//	system("pause");
//	return 0;
//}


//2.ģ��ʵ��strncat



//char *my_strncat(char *arr, char *arr2, int k)
//{
//	char *count = arr;
//	while (*arr)
//	{
//		arr++;
//	}
//	while (k)
//	{
//		*arr++ = *arr2++;
//		--k;
//	}
//	return count;
//}
//int main()
//{
//	char arr[10] = "abcdefg";
//	printf("%s\n", strncat(arr, arr + 2, 1));
//	printf("%s\n", my_strncat(arr, arr + 2, 1));
//	system("pause");
//	return 0;
//}
//3.ģ��ʵ��strncmp


int  my_strncmp(char *str, char *str1, int k)
{
	int temp = 0;
	while (k)
	{
		temp += (*str - *str1);
		k--;
	}
	return temp;
}
int main()
{
	char *str = "abcd";
	char *str1 = "abcdef";
	printf("%d\n", strncmp(str, str1, 1));
	printf("%d\n", my_strncmp(str, str1, 1));
	system("pause");
	return 0;
}