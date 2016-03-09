#pragma once
#include <string>
#include "Seat.h"

using namespace std;

class Seat_Row
{
public:
	static const int MAX_SEATS_PER_ROW = 1000;

private:
	string row_name;
	Seat* seats[MAX_SEATS_PER_ROW];
	int number_of_seats;

public:
	Seat_Row(const string& Row_Name);
	string Row_Name() const { return row_name; };
	int Number_of_Seats() const { return number_of_seats; };
	Seat* Seats(int i) const { return seats[i]; };
	void Add_Seat(Seat* new_seat);
	//void Display() const;
};

