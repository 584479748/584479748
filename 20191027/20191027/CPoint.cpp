/*#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class CPoint
{
public:
	CPoint(int _x1 = 1, int _x2 = 4, int _y1 = 1, int _y2 = 4,int _r = 5) 
		:x1(_x1), x2(_x2), y1(_y1), y2(_y2), r(_r)
	{}
	void PrintCPoint()
	{
		cout << "ֱ�ߵ�����Ϊ��";
		cout << "(" << x1 << "," << y1 << ") " << "(" << x2 << "," << y2 << ") " << endl;
		cout << "Բ�İ뾶Ϊ��" << r << endl;
	}

protected:
	int x1;
	int x2;
	int y1;
	int y2;
	int r;
};


class Cline : public CPoint
{
public:
	void jisuanchangdu()
	{
		double l;
		int a, b;
		a = (x2 - x1)*(x2 - x1);
		b = (y2 - y1)*(y2 - y1);
		l = sqrt((a + b));
		cout << "ֱ�߳���Ϊ��" << l << endl;
	}
	void jisuanxielu()
	{
		double k;
		int a, b;
		a = x2 - x1;
		b = y2 - y1;
		k = b / a;
		cout << "ֱ��б��Ϊ��" << k << endl;

	}
private:
	
};
class CCircle : public CPoint
{
public:
	void jisuanyuanmianji()
	{
		double a = 3.14;
		double s;
		s = a*r*r;
		cout << "Բ�����Ϊ��" << s << endl;
	}
private:
};
int main()
{
	CCircle s1;
	Cline s2;
	s1.PrintCPoint();
	s2.PrintCPoint();
	s1.jisuanyuanmianji();
	s2.jisuanchangdu();
	s2.jisuanxielu();
	system("pause");
	return 0;
}*/


#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class People
{
protected:
	string name;
	int age;
public:
	void InitPeople(string _name= "����",int _age=20)
	{
		name = _name;
		age = _age;
	}

};

class Student : public People
{
public:
	void Init(string _zhuanye = "������",int _chengji = 100)
	{
		zhuanye = _zhuanye;
		chengji = _chengji;
	}
	void Print()
	{
		cout << "������" << name << "���䣺" << age << "רҵ" << zhuanye << "�ɼ�" <<chengji << endl;

	}
private:
	string zhuanye;
	int chengji;

};
class Teacher:public People  
{
public:
	void InitTeacher(string _zhiwu = "������ʦ", string _zhuanye = "����")
	{
		zhiwu = _zhiwu;
		zhuanye = _zhuanye;

	}
	void Print()
	{
		cout << "������" << name << "���䣺" << age << "ְ��" << zhiwu << "רҵ" << zhuanye << endl;
	}
private:
	string zhiwu;
	string zhuanye;

};

int main()
{
	Student  s1;
	Teacher s2;
	s1.InitPeople();
	s1.Init();
	s1.Print();
	s2.InitPeople();
	s2.InitTeacher();
	s2.Print();
	system("pause");
	return 0;
}