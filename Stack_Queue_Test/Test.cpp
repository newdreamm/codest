#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	stack<int, vector<int>> st1;
	queue<int, list<int>> st2;


	stack<int> st3;
	queue<int> st4;


	st1.push(1);
	st1.push(2);
	st1.push(3);
	while (!st1.empty())
	{

		cout << st1.top() << endl;
		st1.pop();
	}
	cout << endl;

	st2.push(4);
	st2.push(5);
	st2.push(6);
	while (!st2.empty())
	{

		cout << st2.front() << endl;
		st2.pop();
	}
	cout << endl;

	st3.push(7);
	st3.push(8);
	st3.push(9);
	while (!st3.empty())
	{

		cout << st3.top() << endl;
		st3.pop();
	}
	cout << endl;

	st4.push(10);
	st4.push(11);
	st4.push(12);
	while (!st4.empty())
	{

		cout << st4.front() << endl;
		st4.pop();
	}
	cout << endl;

	st2.push(4);
	st2.push(5);
	st2.push(6);
	st2.pop();
	st4.push(10);
	st4.push(11);
	st4.push(12);
	st4.pop();


	while (!st2.empty())
	{

		cout << st2.front() << endl;
		st2.pop();
	}
	cout << endl;

	while (!st4.empty())
	{

		cout << st4.front() << endl;
		st4.pop();
	}
	cout << endl;


	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);

	d.push_front(10);
	d.push_front(20);

	for (size_t i = 0; i < d.size(); ++i)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	return 0;
}