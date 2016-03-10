//Anthony Accomando
//Project 3

#include <iostream>
#include "Address.h"
#include "Venue.h"
#include <string>
#include <fstream>

using namespace std;

void Sort_Venue(Venue** Venue_Array, int Num_Venues)
{
        int min;
        Venue* temp;
        
        for (int i=0; i < Num_Venues-1; i++)
        {
            min = i;
            
            for (int j=i+1; j < Num_Venues; j++)
            {
                
                if (*Venue_Array[j] < *Venue_Array[min])
                    min=j;
            }
            
            if (min != i)
            {
                temp = Venue_Array[i];
                Venue_Array[i] = Venue_Array[min];
                Venue_Array[min] = temp;
            }
        }
}


int Get_Venue(Venue* Venue_Array[], int Max_Venues)
{
    int count = 0;
    ifstream infile;
    string filename;
    // for debugging
    //filename = "tampa_venues.txt";
    //infile.open("tampa_venues.txt");
    while (!infile.is_open())
    {
         //Commenting out for debugging
        		cout << "What is the file name?\t";
        		getline(cin, filename);
        infile.open(filename.c_str());
        
        if (!infile.is_open())
        {
            cout << "Failed to open file: " << filename << endl;
            cout << "Invalid input. Please try again.\n";
        }
    }
    
    string name;
    string street_address;
    string city;
    string state;
    int zip_code;
    string throwAway;
    
    // Input file is open
    while (infile.good() && count < Max_Venues)
    {
        
        getline(infile, name, '\n');
        getline(infile, street_address, '\n');
        getline(infile, city, '\n');
        getline(infile, state, '\n');
        infile >> zip_code;
        getline(infile, throwAway, '\n');
        
        if (!infile.good())
        {
            break;
        }
        
        Address *adr = new Address(street_address, city, state, zip_code);
        Venue_Array[count++] = new Venue(name, *adr);
        
        
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

void Display_Venues(Venue** Venue_Array, int Num_Venues)
{
    for (int i = 0; i < Num_Venues; ++i)
    {
        cout << Venue_Array[i];
        cout << endl;
    }
}


int main()
{

	cout << "This program is Venue Sort\n\n";

	Venue* venues[100];
	int count;

	count = Get_Venue(venues, 100);
    cout << count << " venues read from file" << endl << endl;
    cout << "Venues before sort: " << endl;
    Display_Venues(venues, count);
    cout << endl;
    Sort_Venue(venues, count);
    cout << "Venues after sort: " << endl;
    Display_Venues(venues, count);
    

	cin.get(); // Keeps window open
	return 0;
}