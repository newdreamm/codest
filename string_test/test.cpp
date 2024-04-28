#include <iostream>
#include <string>


using namespace std;

void String_test()
{
	string s1;
	string s2("hello");
	string s3(s2);
	s3 += ("world");
	string s4(4,'s');
	string s5("i am w");
	s2.resize(20);
	s2.clear();
	s2 += ('s');
	s2.resize(3, 'c');


	for (size_t i=0; i < s3.size(); i++)
	{
		cout << s3[i] << ' ';
	}
	cout << endl;

	string::reverse_iterator it1 = s3.rbegin();
	while (it1 != s3.rend())
	{
		cout<< *it1 << ' ';
		++it1;
	}
	cout << endl;

	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	s3.push_back('h');
	s3.append("happy");

	

	//cout << s1 << endl;
	//cout << s2 << endl;
	cout << s3 << endl;
	cout << s3.find("wo", 3) << endl;
	cout << s3.substr(5, 3) << endl;
	cout << s3.substr(5) << endl;
	//cout << s4 << endl;
	//cout << s5.size() << endl;
	//cout << s5.capacity() << endl;
	//
	//cout << s1.empty() << endl;
	//cout << s2.capacity() << endl;

}

int main()
{

	String_test();



	return 0;
}


