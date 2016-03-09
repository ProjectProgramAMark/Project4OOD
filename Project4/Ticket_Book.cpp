#include <iostream>
#include "Ticket_Book.h"

using namespace std;

Ticket_Book::Ticket_Book(Performance* performance)
{
	Venue* venue = performance->GetVenue();
	int capacity = venue->Capacity();
	ticket = new Ticket*[capacity];
	Number_of_Tickets = 0;

	int nr_rows = venue->Number_of_Seat_Rows();
	for (int i = 0; i < nr_rows; ++i)
	{
		const Seat_Row* seat_row = venue->Get_Seat_Row(i);
		int number_of_seats = seat_row->Number_of_Seats();
		for (int j = 0; j < number_of_seats; ++j)
		{
			Seat* seat = seat_row->Seats(j);
			ticket[Number_of_Tickets++] = new Ticket(performance, seat);
		}
	}
}


void Ticket_Book::Print_Tickets() const
{
	cout << "------------------------------------" << endl;
	for (int i = 0; i < Number_of_Tickets; i++)
	{
		cout << ticket[i] << endl;
		cout << "-----------------------------------" << endl;
	}
}
