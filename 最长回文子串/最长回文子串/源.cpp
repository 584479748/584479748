#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
		// �������㷨
		string longestPalindrome(string s) {
		//��ʼ��
		int n = s.size();
		// v[i][j] ��ʾ��i���ַ�����j���ַ��Ƿ��ǻ��Ĵ�
		vector<vector<int> > v(n, vector<int>(n, 0));
		int len = 0, left = 0, right = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < i; ++j) // ��j��i�����Բ����ܳ���i
			{
				// ��s[i]����s[j]������£�Ҫôi��j���ڣ�Ҫôv[j][i]����v[j + 1][i - 1]����õ�
				// �ܵ���˵����������ǻ��Ĵ�����s[i]��s[j]��ȣ����Ҳ�ǻ��Ĵ�
				v[j][i] = (s[i] == s[j] && ((i - j < 2) || v[j + 1][i - 1]));
				// ÿ���жϵ�ǰi-j+1�Ƿ�����󳤶�
				if (v[j][i] && i - j + 1 > len)
				{
					len = i - j + 1;
					left = j;
					right = i;
				}
			}
			v[i][i] = 1; // һ���ַ��϶��ǻ��Ĵ�
		}

		return s.substr(left, right - left + 1);
	}
};

int main()
{
	string st = "ababacd";
	Solution p;
	string s = p.longestPalindrome(st);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	system("pause");
	return 0;
}