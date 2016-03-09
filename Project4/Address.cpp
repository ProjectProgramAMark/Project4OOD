#include <iostream>
#include "Address.h"
#include <iomanip>


Address::Address(string Street_Add, string City, string State, int Zip_Code) :
	street_add(Street_Add), city(City), state(State), zip_code(Zip_Code)
{
}


void Address::Display() const
{
	cout.fill('0');
	cout << street_add << endl;
	cout << city << ", " << state << " ";
	cout.width(5);
	cout << zip_code << endl;
}

ostream& operator << (ostream& os, const Address* address)
{
	os << address->GetStreet_address() << endl;
	os << address->GetCity() << ", "
		<< address->GetState()
		<< " " << setfill('0')
		<< setw(5) << address->GetZip_code();
	return os;
}