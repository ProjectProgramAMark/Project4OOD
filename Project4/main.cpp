//Anthony Accomando
//Project 3

#include <iostream>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Performance.h"
#include "Ticket.h"
#include "Ticket_Book.h"
#include <string>
#include <fstream>

using namespace std;

void Clear_Keyboard_Input_Buffer(ifstream &myfile) {
    while (myfile.get() != '\n') ;
}

/*Seat_Row* Create_Seat_Row(const string seat_row_name, int number_of_seats)
{
	Seat_Row* row = new Seat_Row(seat_row_name);
	for (int i = 1; i <= number_of_seats; i++)
	{
		Seat* new_seat = new Seat(seat_row_name, i);
		row->Add_Seat(new_seat);
	}
	return row;
}*/

int Get_Venue(Venue** Venue_Array, int Max_Venues)
{
    int count = 0;
    ifstream infile;
    string filename;
    filename = "tampa_venues.txt";
    //infile.open("tampa_venues.txt");
    system("pwd");
    while (!infile.is_open())
    {
        // Commenting out for debugging
        //		cout << "What is the file name?\n";
        //		getline(cin, filename);
        infile.open(filename.c_str());
        
        if (!infile.is_open())
        {
            cout << "Failed to open file: " << filename << endl;
            cout << "Invalid input. Please try again.\n";
        }
    }
    
    // Input file is open
    while ((count < Max_Venues) && infile.good())
    {
        string name;
        string street_address;
        string city;
        string state;
        int zip_code = 0;
        
        getline(infile, name);
        getline(infile, street_address);
        getline(infile, city);
        getline(infile, state);
        infile >> zip_code;
        Clear_Keyboard_Input_Buffer(infile);
        
        /*cout << name << endl;				// these are just to check if its reading it.
         cout << street_address << endl;		//
         cout << city << endl;				//
         cout << state << endl;				//
         cout << zip_code << endl;			//
         cout << count << endl;*/
        
        //Address* adr = Create_Address(street_address, city, state, zip_code);
        Address *adr = new Address(street_address, city, state, zip_code);
        //		cout << adr << endl;;			// its sending the address info to address func and creaing addresses
        //		cout << count << endl;
        Venue* venue = new Venue(name, *adr);
        cout << venue << endl;
        Venue_Array[count++] = new Venue(name, *adr);
        cout << count << endl;
        
        
        
        
    }
    if (infile.eof())
    {
        cout << "End of file\n";
    }
    else
    {
        cout << "Error reading file\n";
        count = -1;
    }
    infile.close();
    return count;
}

void Display_Venues(Venue** Venue_Array, int Max_Venues)
{
	for (int i = 0; i < Max_Venues; ++i)
	{
		//cout << *Venue_Array[i];
		cout << endl;
	}
}

/*Venue* Create_Venue()
{
//string name;

//Address* adr = Create_Address();
//Venue* venue = new Venue(name, *adr);

Seat_Row* sr = Create_Seat_Row("A", 4);
venue->Add_Seat_Row(sr);

sr = Create_Seat_Row("B", 4);
venue->Add_Seat_Row(sr);

sr = Create_Seat_Row("C", 4);
venue->Add_Seat_Row(sr);

return venue;
}*/

/*Performance* Create_Performance(Venue** Venue_Array, int Max_Venues)
{
for (int i = 0; i < Max_Venues; ++i)
{
Date show_date = { 4, 2, 1016, 20, 0 };

Performance* p = new Performance("Billy Elliot", Venue_Array[i], show_date);
}
return p;
}*/


int main()
{

	cout << "This program is Venue Sort\n\n\n";


	/*Address* adr = Create_Address();
	adr->Display();
	cout << endl;

	Seat* seat = new Seat("A", 1);
	seat->Display();
	cout << endl;

	Seat_Row* row = Create_Seat_Row("Test", 4);
	row->Display();
	cout << endl;

	Venue* venue = Create_Venue();
	venue->Display();
	cout << endl;

	Performance* performance = Create_Performance(venue);
	performance->Display();
	cout << endl;*/

	Venue* venues[100];
	int count;
	

	count = Get_Venue(venues, 100);
//	cout << count << " venues read\n";

	
	//Display_Venues(venues, count);

	//Display_Venues(venues, count);

	//Venue* venue = Create_Venue();
	//Performance* performance = Create_Performance(venue);
	//Ticket_Book* ticket_book = new Ticket_Book(performance);
	//ticket_book->Print_Tickets();

	/*Ticket* ticket = Create_Ticket(performance, seat);
	ticket->Display();
	cout << endl;*/

	cin.get(); // Keeps window open
	return 0;
}