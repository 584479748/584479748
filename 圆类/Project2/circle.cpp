#include<iostream>
#include<stdlib.h>


using namespace std;

class Circle
{
public:
	void InitCircle(int _r = 10) 
	{
		r = _r;
	}
	double  qiuzhouchang()
	{
		int d = r * 2;
		double a = 3.14;
		return a*d;
	}
	double qiumianji()
	{
		double s;
		double a = 3.14;
		s = a*r*r;
		return s;
	}
private:
	int r;
};

int main()
{
	Circle s1;
	s1.InitCircle();
	cout << "Բ���ܳ�Ϊ��" << s1.qiuzhouchang() << "Բ�����Ϊ��" << s1.qiumianji() << endl;
	system("pause");
	return 0;
}