#include<iostream>

using namespace std;


//ֱ�Ӳ�������
//����������Ԫ��һ�������뵽�Ѿ��ź�˳��Ĳ�
void Insertsort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j;
		for ( j = i-1; a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j+1] = temp;
	}
}
int main()
{
	int a[10] = { 1, 3, 5, 6, 4, 3, 8, 9, 0, 10 };
	
	Insertsort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i]<<' ' ;
	}

	system("pause");
	return 0;
}