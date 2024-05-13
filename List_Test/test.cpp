#include<iostream>
#include<list>
#include<vector>
#include"List.h"

using namespace std;


void PrintList(const list<int>& l)
{
	list<int>::const_iterator it = l.begin();
	while (it != l.end())
	{

		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void List_test1()
{
	list<int> l1(5, 3);
	list<int> l2();
	list<int> l3{ 1,2,3,4,5 };


	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{

		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l3)
	{

		cout << e << " ";

	}
	cout << endl;


}


void List_test2()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	//����
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//����
	auto it2 = l.rbegin();
	while (it2 != l.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}

void List_test3()
{
	int array[] = { 1,2,3 };
	list<int>l(array, array + sizeof(array) / sizeof(array[0]));

	l.push_back(4);
	l.push_front(0);
	PrintList(l);

	l.pop_back();
	l.pop_front();
	PrintList(l);
}


void List_test4()
{
	int array1[] = { 1,2,3 };
	list<int>l(array1, array1 + sizeof(array1) / sizeof(array1[0]));

	//��ȡ�����еڶ������
	auto pos = ++l.begin();
	cout << *pos << endl;

	l.insert(pos, 4);
	PrintList(l);

	//��posǰ�������4
	l.insert(pos, 5, 4);
	PrintList(l);


	// ��posǰ����[v.begin(), v.end)�����е�Ԫ��
	vector<int> v{ 2,3};
	l.insert(pos, v.begin(), v.end());
	PrintList(l);

	// ɾ��posλ���ϵ�Ԫ��
	l.erase(pos);
	PrintList(l);

	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
	l.erase(l.begin(), l.end());
	PrintList(l);

}

void List_test5()
{
	int array1[] = { 1,3,5 };
	list<int>l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(l1);


	list<int> l2{1,2,3};
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

	l1.clear();
	cout << l1.size() << endl;

}


int main()
{



	//List_test1();
	//List_test2();
	//List_test3();
	//List_test4();
	//List_test5();
	TestBiteList1();
	TestBiteList2();
	TestBiteList3();
	TestBiteList4();

	return 0;
}