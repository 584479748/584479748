//1ֻ�����������º�ÿ������һֻ���ӣ�N�º��ж���ֵ����
#include<iostream>
#include<vector>
using namespace std;

int getrabbit(int month)
{
	int n = 0;
	vector<int> sum ;
	sum.resize(month + 1);
	sum[0] = 1;
	for (int i = 1; i <= month; i++)
	{
		if (i>=3)
		{
			n = sum[i-2];
		}
		
		sum[i]=sum[i-1]+ n;
		
	
	}
	return sum[month];
}
int main()
{
	int month;
	while (cin>>month)
	{
		int sum = getrabbit(month);
		cout << sum << endl;
	}
	system("pause");
	return 0;
}