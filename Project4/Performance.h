#pragma once
#include <string>
#include "Venue.h"

using namespace std;

struct Date
{
	int Month;
	int Day;
	int Year;
	int Hour;
	int Minute;
};

class Performance
{
private:
	string name;
	Venue* venue;
	Date show_date;


public:
	Performance(const string& name_, Venue* venue_, Date show_date_);
	string GetName() const { return name; };
	Date Show_Date() const { return show_date; };
	Venue* GetVenue() const { return venue; };
	//void Display() const;
};

ostream& operator << (ostream& os, const Performance* performance);
ostream& operator << (ostream& os, const Date& show_date);
