#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

//void my(int arr[], int sz)
//{
//	int i = 0;
//	while (sz>1)
//	{
//		for (i = 0; i < sz - 1; i++)
//		{
//			if (arr[i]%2==0)
//			{
//				int temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//		sz--;
//	}
//}

//void my(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz;
//	int temp = 0;
//	while (left < right)
//	{
//		//����ż��
//		while ((arr[left] % 2 != 0) && (left<right))
//		{
//			left++;
//		}
//		//��������
//		while ((arr[right] % 2 == 0) && (left<right))
//		{
//			right--;
//		}
//		temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//2.
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9

int find(int arr[3][3], int row, int col, int k)
{
	int i;
	int j = col - 1;
	for (i = 0; i <3; i++)
	{
		if (arr[i][j]==k)
		{
			return 1;
		}
		if (arr[i][j>k])
			break;
	}
	if (i >= 3)
	{
		return 0;
	}
	if (arr[i][j - 1] == k)
	{
		return 1;
	}
	else if (arr[i][j - 2] == k)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ret = find(arr, 7, 3, 13);
	if (ret == 0)
	{
		printf("������:>");
	}
	else
	{
		printf("���ڣ�>");
	}
	system("pause");
	return 0;
}