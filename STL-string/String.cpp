#include<iostream>
#include<string>
using namespace std;



//void string1() {
//
//	string s1("hello");
//	s1 += ' ';
//	s1 += "world";
//	cout << s1 << endl;
//
//	//遍历
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	//迭代器
//	string::iterator itl = s1.begin();
//	while (itl != s1.end())
//	{
//		cout << *itl << " ";
//		++itl;
//	}
//	cout << endl;
//	//范围for
//	for (auto e : s1)
//	{
//		cout << e << " ";
//
//	}
//	cout << endl;
//
//	//获取字符数组的首地址，用C字符串的形式遍历
//	const char* str = s1.c_str();
//	while (*str)
//	{
//		cout << *str << " ";
//		++str;
//	}
//	cout << endl;
//
//	cout << s1 << endl;//调用的string重载operator<<
//	cout << s1.c_str() << endl;//直接输出 const char*
//
//	s1 += '\0';
//	s1 += "hello";
//
//	cout << s1 << endl;//调用的string重载operator<<
//	cout << s1.c_str() << endl;//直接输出 const char*
//}
//
//
//void string2()
//{
//	string s1("string.cpp");
//	string s2("string.c");
//	string s3("string.txt");
//
//	size_t pos1 = s1.find('.'); 
//	if (pos1 != string::npos)
//	{
//		cout << s1.substr(pos1) << endl;
//		
//		// string substr(size_t pos = 0, size_t len = npos) const;
//	}
//
//	size_t pos2 = s2.find('.');
//
//	if (pos2 != string::npos)
//	{
//		cout << s2.substr(pos2) << endl;
//	}
//
//	size_t pos3 = s3.find('.');
//	if (pos3 != string::npos)
//	{
//		cout << s3.substr(pos3) << endl;
//	}
//
//}
//int main() {
//
//	//string1();
//	string2();
//
//	return 0;
//}
////////////////////////////////////////////////////////////



//获取字符串最后一个单词的长度

int main()
{

	string s;
	getline(cin, s);//cin不能有空格，所以用getline

	size_t pos = s.rfind(' ');
	cout << s.size() - (pos +1) << endl;


	return 0;
}



