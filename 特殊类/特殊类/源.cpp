#include<iostream>

using namespace std;

class heaponly
{
public:
	static heaponly* creatobject()
	{
		return new heaponly;
	}
private:
	heaponly()//�����캯������Ϊ˽�У����������ܵ��ù��캯��
	{

	}
	heaponly(const heaponly&);//������ʵ�֣�����Ҫ�õ��������캯��������Ϊ˽�У���ֹ�Լ�ʵ�ֿ�������
	//heaponly(const heaponly&)c++11 ���߱���������Ҫ��������
};

int main()
{
	heaponly *p = heaponly::creatobject();
	return 0;
}