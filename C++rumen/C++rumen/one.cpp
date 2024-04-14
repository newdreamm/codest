#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Stack
{
	//成员函数
public:
	void Push(int x)
	{

	}//类里面定义
	void Pop();

	//成员变量                          //这些都是声明
//private:
	int* _a;
	int _size;
	int _capacity;
};

//void Stack::Push(int x)
//{
//
//}//类外面定义
int main()
{
	/*int a;
	std::cout << "hello,wold!" << endl;
	cin >> a;
	cout << a << endl;*/
	Stack s;//类实例化出对象，相当于定义出了类的成员变量
	s._a = nullptr;
	cout << sizeof(s) << endl;
	return 0;
}