#include<iostream>
using namespace std;
class HeapOnly
{
public:
	static HeapOnly* CreateObject()//��̬��Ա�������Բ�ͨ���������
	{
		return new HeapOnly;
	}
	~HeapOnly()
	{}
private:
	//C++98
	HeapOnly(const HeapOnly&);//ֻ�����������ǲ���Ҫʵ�֣�
	//��C++11��������������㣬��Ϊ���ù�Ȩ��
	//HeapOnly(const HeapOnly&) = delete;//���ù�Ȩ��
private:
	HeapOnly()//���캯��
	{}
};
int main()
{
	HeapOnly *p = HeapOnly::CreateObject();//�ڶ��ϴ�������1.���ٿռ�2.���ù��캯����
	return 0;
}
