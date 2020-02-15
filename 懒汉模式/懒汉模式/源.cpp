//����ģʽ ��һ��ʹ��ʱ���� �ӳټ���
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
class Slingleton{
public:
	static volatile Slingleton* getinstrance()
	{
		if (m_pIns == nullptr)//��ֹ�߳�����
		{
			m_mutex.lock();
			if (m_pIns == nullptr)//volatile Slingleton* Slingleton::m_pIns = nullptr;
								  //������ľ�̬������ʼ��Ϊ�գ���һ��ʹ��ʱ�������󣬺����ڵ���
								  //ָ�벻Ϊ�վ��޷���������

			{
				m_pIns = new Slingleton;
			}
			m_mutex.unlock();
		}
		return m_pIns;
	}
	class Gc{
	public:
		~Gc()
		{
			if (m_pIns)
			{
				delete m_pIns;
				m_pIns = nullptr;
			}
		}
	};
private:
	Slingleton()
	{
	}
	Slingleton(const Slingleton &) = delete;
	Slingleton &operator=(const Slingleton &) = delete;
	static volatile Slingleton* m_pIns ;
	static mutex m_mutex;
	static Gc m_gc;//��̬��Ա�����ڳ������ʱ���٣�m_gc�ڳ������ʱ���������ͷ�new���ٵĿռ�
};
volatile Slingleton* Slingleton::m_pIns = nullptr;
mutex Slingleton::m_mutex;
Slingleton::Gc m_gc;


void Treadfunc()
{
	cout << Slingleton::getinstrance() << endl;
}
void Test()
{
	thread t1(Treadfunc);	
	thread t2(Treadfunc);
	thread t3(Treadfunc);
	thread t4(Treadfunc);
	thread t5(Treadfunc);
	thread t6(Treadfunc);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
}
int main()
{
	Test();
	return 0;
}