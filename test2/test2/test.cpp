#include<iostream>
using namespace std;




// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//    void f1() {}
//private:
//    int _a;
//};

// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};

// 类中什么都没有---空类
//class A3
//{};

//typedef int DataType;
//class Stack
//{
//public:
//	void Init()
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * 3);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = 3;
//		_size = 0;
//	}
//		void Push(DataType data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	void Pop()
//	{
//		if (Empty())
//			return;
//		_size--;
//	}
//	DataType Top() { return _array[_size - 1]; }
//	int Empty() { return 0 == _size; }
//	int Size() { return _size; }
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity *
//				sizeof(DataType));
//			if (temp == NULL)
//			{
//				perror("realloc申请空间失败!!!");
//				return;
//			}
//			_array = temp;
//			_capacity = newcapacity;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//int main()
//{
//	Stack s;
//	s.Init();
//	
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Pop();
//	s.Pop();
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//	s.Destroy();
//	return 0;
//}

//
//int main()
//{
//
//    cout << sizeof(A3) << endl;
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}


//class Time
//{
//public:
//    Time()
//    {
//        _hour = 1;
//        _minute = 1;
//        _second = 1;
//        
//           /* 注意：在编译器生成的默认拷贝构造函数中，内置类型是按照字节方式直接拷贝的，而自定
//            义类型是调用其拷贝构造函数完成拷贝的。
//            编译器生成的默认拷贝构造函数已经可以完成字节序的值拷贝了，还需要自己显式实现吗？
//            当然像日期类这样的类是没必要的。*/
//    }
//    Time(const Time& t)
//    {
//        _hour = t._hour;
//        _minute = t._minute;
//        _second = t._second;
//        cout << "Time::Time(const Time&)" << endl;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//int main()
//{
//    Date d1;
//
//    // 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//    // 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构
//   
//    Date d2(d1);
//    return 0;
//}

class A
{
public:
     int _a;
     int _b;

     A(int a, int b)
         : _a(a),
           _b(b)
     {}

     void swap(int& _a, int& _b)
    {
         int tmp;
         tmp = _a;
         _a = _b;
         _b = tmp;
         cout << _a << " " << _b << endl;
     }


 };


int main()
{
     A s(2,3);
   
     int x = 0;
     int y = 0;
     cin >> x >> y;
     s.swap(x,y);
     return 0;

 }