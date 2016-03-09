#include <iostream>
#include "Ticket.h"

using namespace std;

Ticket::Ticket(Performance* performance_, Seat* seat_) :
	performance(performance_), seat(seat_), sold(false)
{
}


/*void Ticket::Display() const
{

cout << "Tickets: \n" << endl;
cout << "performance: " << performance << endl;
cout << "venue: " << venue << endl;
cout << "seat: " << seat << endl;
}*/

void Ticket::Sell()
{
	sold = true;
}

ostream& operator << (ostream& os, const Ticket* ticket)
{
	os << ticket->GetPerformance() << endl;
	os << ticket->GetSeat();
	return os;
}