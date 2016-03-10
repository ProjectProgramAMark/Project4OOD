#pragma once
#include <string>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"

using namespace std;

class Venue
{
public:
	static const int MAX_SEAT_ROWS = 1000;

private:
	string name;
	Address* address;
	Seat_Row* seat_rows[MAX_SEAT_ROWS];
	int number_of_seat_rows;
	int capacity;

public:
	Venue(const string& name_, Address& address_);
	void Add_Seat_Row(Seat_Row* seat_row);
	int Capacity() const { return capacity; };		// Number of Seats
	int Number_of_Seat_Rows() const { return number_of_seat_rows; };
	Address* GetAddress() const { return address; };
	string GetName() const { return name; };
	Seat_Row* Get_Seat_Row(int i) const { return seat_rows[i]; };
	void Display() const;
	//bool operator > (const Venue& other)  const;
    friend bool operator<(const Venue& venue1, const Venue& venue2);

};

ostream& operator << (ostream& os, const Venue* venue);



