#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Stack
{
	//��Ա����
public:
	void Push(int x)
	{

	}//�����涨��
	void Pop();

	//��Ա����                          //��Щ��������
//private:
	int* _a;
	int _size;
	int _capacity;
};

//void Stack::Push(int x)
//{
//
//}//�����涨��
int main()
{
	/*int a;
	std::cout << "hello,wold!" << endl;
	cin >> a;
	cout << a << endl;*/
	Stack s;//��ʵ�����������൱�ڶ��������ĳ�Ա����
	s._a = nullptr;
	cout << sizeof(s) << endl;
	return 0;
}