#include<iostream>
#include<functional>
#include<vector>
#include<deque>

using namespace std;
#if 0
namespace bid
{
	//ģ��ʵ��ջ
	template<class T, class Container = deque<T>>
	class Stack//ջ
	{
	public:

		Stack(){}//����ȳ�
		//��ջ  //ֱ�ӵ���������ķ�������	
		void push(const T& x){ _s.push_back(x); }
		void pop(){ _s.pop_back(); }//��ջ
		T& top(){ return _s.back(); }
		const T& top() const{ return _s.back(); }
		size_t size() const	{ return _s.size(); }
		bool empty() const{ return _s.empty(); }
	private:
		Container _s;
	};
}
void StackTest()
{
	bid::Stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.size() << endl;
	cout << s1.top() << endl;

	s1.pop();
	s1.pop();
	cout << s1.size() << endl;
	cout << s1.top() << endl;

}
int main()
{
	StackTest();
	system("pause");
	return 0;
}
#endif


namespace bit
{
	//ģ��ʵ�ֶ���
	template<class T, class Con = deque<T>>//�õ���˫�˶��У�Ҳ��list
	class Queue//����
	{//�Ƚ��ȳ�
	public:
		Queue(){}
		void push(const T& x){ _q.push_back(x); }
		void pop(){ _q.pop_front(); }
		//
		T& front(){ return _q.front(); }
		const T& front() const{ return _q.front(); }
		T& back(){ return _q.back(); }
		const T& back() const{ return _q.back(); }
		size_t size() const{ return _q.size(); }
		bool empty() const{ return _q.empty(); }
	private:
		Con _q;
	};
}
void QueueTest()
{
	bit::Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
}

int main()
{
	QueueTest();
	system("pause");
	return 0;
}
