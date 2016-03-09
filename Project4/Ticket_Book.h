#pragma once
#include <iostream>
#include <string>
#include "Ticket.h"
#include "Performance.h"

using namespace std;

class Ticket_Book //: public Ticket
{
private:
	Ticket** ticket;
	int Number_of_Tickets;

public:
	Ticket_Book(Performance* performance_);
	void Print_Tickets() const;
};

