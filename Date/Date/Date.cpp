#include <iostream>
using namespace std;




class Date
{
public:

	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (  >= 0 && month >= 1 && month = 12
			&& day >= 1 && day <= GetMonthDay( year,month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
	
		else
		{
			cout<<"非法日期"<<endl;
		}
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d;
	Date d1(2020, 4, 11);
	d.Print();
	return 0;
}
