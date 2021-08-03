
#ifndef MONTH_H
#define MONTH_H

#include<string>
using namespace std;

class Month; // forward declaration

ostream& operator<<(ostream&, const Month&);
istream& operator>>(istream&, const Month&);

class Month
{
private:
	string monthName_;
	int monthNum_;

public:
	// constructors
	Month();
	Month(string);
	Month(int);

	// mutators
	void setName(string);
	void setNum(int);

	// accessor 
	string getName() const;
	int getNum() const;

	// overloaded 
	const Month operator=(const Month&);
	friend ostream& operator<<(ostream&, const Month&);
	friend istream& operator>>(istream&, Month&);
	Month operator++();
	Month operator++(int); // postfix

};

#endif 




