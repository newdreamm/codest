#include<iostream>
#include<vector>
#include<string>
#include "Vector.h"

using namespace std;


void VectorTest()
{

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";

	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";

	}
	cout << endl;

	cout << v.max_size() << endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	//v.pop_back();

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void VectorTest2()
{
	vector<int> v(10, 4);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{

		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.insert((v.begin())+1, 5);

	v.insert(v.begin(), 3, 5);
	
	vector<int>::iterator it2 = v.begin();
	while (it2 != v.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;


	v.erase(v.begin(), v.begin() + 3);
	for (auto e : v)
	{
		cout << e << " ";

	}
	cout << endl;
}

void VectorTest3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << v.capacity() << endl;
	v.reserve(10);
	cout << v.capacity() << endl;
	v.reserve(4);
	cout << v.capacity() << endl;

	v.resize(8);
	v.resize(15, 1);
	v.resize(3);

	for (auto e : v)
	{
		cout << e << " ";

	}
	cout << endl;

}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	//v.reserve(100);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void VectorTest4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.assign(10, 1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	v.assign(v1.begin(), v1.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	string str("hello world");
	v.assign(str.begin(), str.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.assign(++str.begin(), --str.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void SwapTest()
{
	vector<int> v = { 1,2,3 };
	vector<int> v1 = { 2,3,4 };

	swap(v, v1);

	for (auto e : v)
	{
		cout << e << " ";

	}
	cout << endl;
	for (auto e : v1)
	{
		cout << e << " ";

	}
	cout << endl;
}


int main()
{

	//VectorTest();
	//VectorTest2();
	//VectorTest3();
	//TestVectorExpand();
	//VectorTest4();
	//SwapTest();
	TestBitVector2();

	return 0;
}