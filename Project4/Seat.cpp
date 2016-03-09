#include <iostream>
#include "Seat.h"



Seat::Seat(string Row_Name, int Seat_Number) :
	seat_row_name(Row_Name), seat_number(Seat_Number)
{
}


/*void Seat::Display() const
{
cout << "Row " << seat_row_name << " Seat " << seat_number << endl;
}*/

ostream& operator << (ostream& os, const Seat* seat)
{
	os << "Row " << seat->Seat_Row_Name()
		<< " Seat " << seat->Seat_Number();
	return os;
}
