#include <iostream>
#include <string.h>
#include "Venue.h"
#include "cassert"
#include <fstream>

using namespace std;

Venue::Venue(const string& name_, Address& address_) :
	name(name_), address(&address_), capacity(0)
{
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


