#include <iostream>
#include <string.h>
#include "Venue.h"
#include "cassert"
#include "Seat_Row.h"

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

void Venue::Display() const
{
cout << name << endl;
address->Display();
/*for (int i = 0; i < number_of_seat_rows; ++i)
{
const Seat_Row* row = seat_rows[i];
row->Display();
}*/
}

ostream& operator<<(ostream& os, const Venue* venue)
{
	os << venue->GetName() << endl;
	os << venue->GetAddress() << endl;
	return os;
}

/*bool Venue::operator > (const Venue& other)  const
{

if (address == other.address)
{
return name > other.name;
}

else if (address < other.address)
{
return name > other.name;
}

return name > other.name;
}*/
