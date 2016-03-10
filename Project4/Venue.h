#pragma once
#include <string>
#include "Address.h"

using namespace std;

class Venue
{
public:
	static const int MAX_SEAT_ROWS = 1000;

private:
	string name;
	Address* address;
	int number_of_seat_rows;
	int capacity;

public:
	Venue(const string& name_, Address& address_);
	int Capacity() const { return capacity; };		// Number of Seats
	int Number_of_Seat_Rows() const { return number_of_seat_rows; };
	Address* GetAddress() const { return address; };
	string GetName() const { return name; };
	void Display() const;
	//bool operator > (const Venue& other)  const;
    friend bool operator<(const Venue& venue1, const Venue& venue2);

};

ostream& operator << (ostream& os, const Venue* venue);



