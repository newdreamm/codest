#include<iostream>
using namespace std;



//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//			cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name;
//	//string _sex;
//	//int _age;
//};
//
//class Student :public Person
//{
//
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//
//protected:
//	int _num;
//};
//
//
//
//int main()
//{
//	/*Student s;
//	s._age = 18;
//	s._name = "zhangsan";
//	s._No = 23002;
//	s._sex = "��";
//
//	Person p = s;
//	Person& rp = s;
//	
//	
//	cout << s._age << endl;
//	cout << s._name << endl;
//	cout << s._No<< endl;
//	cout << s._sex << endl;
//	cout << p._age << endl;
//	cout << p._name << endl;
//	cout << p._sex << endl;
//	cout << rp._age << endl;
//	cout << rp._name << endl;
//	cout << rp._sex << endl;*/
//
//
//	
//	Student s("zhangsan",22222);
//	Student s1("sssk",18);
//	Student s2(s1);
//	s1 = s2;
//	
//
//	return 0;
//}
//
//
//
//
//// �̳�
//class X
//{
//	int _x;
//};
//
//class Y : public X
//{
//	int _y;
//};
//
//// ���
//class M
//{
//	int _m;
//};
//
//class N
//{
//	M _mm;
//	int _n;
//};


//��Ԫ��ϵ���̳�
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
int main()
{
	Person p;
	Student s;
	Display(p, s);
}
