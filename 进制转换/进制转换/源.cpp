#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	int num;//����һ��ʮ������
	int n;//��Ҫת���Ľ�����
	cin >> num >> n;

	string ret, total = "0123456789ABCDEF";
	//����Ǹ���
	bool flag = false;
	if (num < 0)
	{
		num = 0 - num;
		flag = true;
	}
	while (num)
	{
		ret += total[num % n];
		num /= n;
	}
	if (flag) ret += '-';
	reverse(ret.begin(), ret.end());
	cout << ret << endl;
	system("pause");
	return 0;
}