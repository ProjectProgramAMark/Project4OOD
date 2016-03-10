#pragma once
#include <string>

using namespace std;


class Address
{
private:
	string street_add;
	string city;
	string state; // 2 charcters
	int zip_code; // 5 digits

public:
	Address(string Street_Add, string City, string State, int Zip_Code);

	void Display() const;
	string GetStreet_address() const { return street_add; };
	string GetCity() const { return city; };
	string GetState() const { return state; };
	int Get_Zip_code() const { return zip_code; };
};
ostream& operator << (ostream& os, const Address* address);


