#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//1.�������ָ��
//����ָ����ָָ�������ַ��ָ�룬����Ϊָ�룬Ӧע����������ָ����ָ������
//ָ��������ָ�����Ԫ����ָ�����͡�

//2.��⺯��ָ��Ͷ���
//����ָ�������������ڵ�ַ������ͨ������ָ�������ú�������һ�������ĵ�ַ��ֵ��
//ָ�룬�����ָ���Ϊ����ָ�룬����ͨ�����ָ�������ú���
//ָ�뺯����ָ�������ص���һ����ֵַ������ʹ���ڷ��������ĳһԪ�ص�ַ


//3.��⺯��ָ������Ͷ��壬ת�Ʊ�
//����ָ�����������飬ֻ���������Ԫ���Ǻ���ָ�루ָ������ڵ�ַ��ָ�룩��


//4.���ָ����ָ�������ָ��Ͷ���
//�Ѻ���ָ������ĵ�ַ��ֵ��һ��ָ�룬�����ָ���Ϊָ����ָ�������ָ�룬
//����ָ�롣


//5.���ص�������ʹ��
//�ص�������ָ��������ڣ�����ָ�룩��ַ��Ϊ����������ĺ�����ͨ����ĺ�
//������ʵ���Լ��ĺ���


//6.��ɿ��ô������ϰ��


//7.��ϰʹ��qsort��������������͵����ݡ�


//int cmp(const void *a, const void *b)
//{
//	return(*(int *)a - *(int *)b);//��С�����˳������
////return(*(int *)b - *(int *)a);//�Ӵ�С��˳������
//}
//int main()
//{
//
//	int arr[1000] ;
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for(i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	 qsort(arr, n, sizeof(arr[0]), cmp);
//	 
//	 for (i = 0; i < n; i++)
//	 {
//		 printf("%d", arr[i]);
//	 }
//	system("pause");
//	return 0;
//}
//

//int cmp(const void *a, const void *b)
//{
//	return(*(double *)a > *(double *)b ? 1 : -1);//��С�����˳������
//	//return(*(int *)b - *(int *)a);//�Ӵ�С��˳������
//}
//
//
//int main()
//{
//
//	double arr[10];
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%f", &arr[i]);
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp);
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%f", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

//8.ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������


void my_qsort(int arr[], int n)
{
	//����
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
}
	
int main()
{
	int arr[1000];
	int n = 0;//������Ҫ����ĸ���
	scanf("%d", &n);
	//��ʼ������
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	my_qsort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}