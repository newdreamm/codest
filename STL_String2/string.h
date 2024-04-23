#define _CRT_SECURE_NO_WARNINGS

//namespace st
//{
//	class string
//	{
//	public:
//	
//		string(const char* str="")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		string& operator=(const string& s)
//		{
//
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			
//
//			return *this;
//
//		 }
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//
//		}
//	private:
//		char* _str;
//
//	};
//
//	void test_string1()
//	{
//		string s1("hello");
//		string s2;
//		for (size_t i = 0; i < s1.size(); ++i)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//	}
//
//	void test_string2()
//	{
//		string s1("hello");
//		string s2(s1);
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		string s3("world");
//		s1 = s3;
//
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//
//
//	}
//
//}
#define EXAMPLE_MACRO_NAME

namespace st
{
	class string
	{
	public:

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		char& operator[]( size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		void reserve(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;

			_capacity = n;
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				//reserve();
				reserve(_capacity * 2);
			}

			strcpy(_str + _size, str);
			_size += len;
			// ...
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

	private:
		char* _str;
		size_t _size;  //已经有多少个有效字符
		size_t _capacity;  //能存多少个有效字符

	};

	ostream& operator<< (ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			cout << s[i];
		}
		return out;
	}

	void test_string1()
	{
		string s1("abc");
		string s2("hello");
		cout << s1 << endl;
		cout << s2 << endl;
		s2.append("abc");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	void test_string2()
	{
		


	}

}
