#pragma once
#include <string>
#include "Performance.h"
#include "Seat.h"

using namespace std;

class Ticket
{
private:
	Performance* performance;
	Seat* seat;
	bool sold;

public:
	Ticket(Performance* performance_, Seat* seat_);
	Performance* GetPerformance() const { return performance; };
	Seat* GetSeat() const { return seat; };
	bool GetSold() const { return sold; };
	//void Display() const;
	void Sell();
};

ostream& operator << (ostream& os, const Ticket* ticket);

