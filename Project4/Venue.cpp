#include <iostream>
#include <string.h>
#include "Venue.h"
#include "cassert"
#include "Seat_Row.h"
#include <fstream>

using namespace std;

Venue::Venue(const string& name_, Address& address_) :
	name(name_), address(&address_), number_of_seat_rows(0), capacity(0)
{
}


void Venue::Add_Seat_Row(Seat_Row* seat_row)
{
	assert(number_of_seat_rows < MAX_SEAT_ROWS - 1);
	seat_rows[number_of_seat_rows++] = seat_row;
	capacity += seat_row->Number_of_Seats();
}



ostream& operator<<(ostream& os, const Venue* venue)
{
	os << venue->GetName() << endl;
	os << venue->GetAddress() << endl;
	return os;
}

bool operator<(const Venue& venue1, const Venue& venue2)
{
    if(venue1.GetAddress()->Get_Zip_code() == venue2.GetAddress()->Get_Zip_code()) {
        return (venue1.name.compare(venue2.name) < 0);
    }
    return (venue1.GetAddress()->Get_Zip_code() < venue2.GetAddress()->Get_Zip_code());
}


