#include "Month.h"
#include <iostream>
#include <vector>

using namespace std;

constexpr int NUM_MONTHS = 12;

struct months
{
	int numMonth = 0;
	string nameMonth = "";
};

months populateArray(string month, int num)
{
	months tempMonth;

	tempMonth.nameMonth = month;
	tempMonth.numMonth = num;

	return tempMonth;
}

months monthArr[NUM_MONTHS] = { populateArray("Janurary",1),  populateArray("February",2),  populateArray("March",3),
								 populateArray("April",4),  populateArray("May",5),  populateArray("June",6),
								 populateArray("July",7),  populateArray("August",8),  populateArray("September",9),
								 populateArray("October",10),  populateArray("November",11),  populateArray("December",12) };
Month::Month() // default constructor
{
	setName(monthArr[0].nameMonth);
	setNum(monthArr[0].numMonth);
}

Month::Month(string name)
{
	bool found = 0;
	int i = 0;

	while (!found)
	{
		if (name == monthArr[i].nameMonth)
		{
			setName(monthArr[i].nameMonth);
			setNum(monthArr[i].numMonth);

			found = 1;
		}

		i++;
	}
}

Month::Month(int num)
{
	bool found = 0;
	int i = 0;

	while (!found)
	{
		if (num == monthArr[i].numMonth)
		{
			setName(monthArr[i].nameMonth);
			setNum(monthArr[i].numMonth);

			found = 1;
		}

		i++;
	}
}

Month Month :: operator++()
{
	++monthNum_;
	if (getNum() == 13)
	{
		setNum(1);
	}
	setName(monthArr[monthNum_-1].nameMonth);
	setNum(monthArr[monthNum_-1].numMonth);

	return *this;
}

Month Month :: operator++(int)
{
	Month tempMonth(this->getNum());

	monthNum_++;
	if (getNum() == 13)
	{
		setNum(1);
	}
	setName(monthArr[monthNum_-1].nameMonth);
	setNum(monthArr[monthNum_-1].numMonth);

	return tempMonth;
}

istream& operator >> (istream& iStrm, Month& obj)
{

	string name;
	bool found = 0;
	int i = 0;

	cout << "Enter the name of a month: ";
	cin >> name;

	while (!found)
	{
		if (name == monthArr[i].nameMonth)
		{
			obj.setName(monthArr[i].nameMonth);
			obj.setNum(monthArr[i].numMonth);

			found = 1;
		}

		i++;
	}

	if (!found)
	{
		cout << "Invalid!!!!" << endl;
	}

	return iStrm;
}

ostream& operator << (ostream& oStrm, Month& obj)
{
	oStrm << "The month is " << obj.getName() << " and the Number is " << obj.getNum() << endl;
	return oStrm;
}

const Month Month :: operator=(const Month& right)
{
	if (this == &right)
	{
		return *this;
	}

	setName(right.getName());
	setNum(right.getNum());
}
