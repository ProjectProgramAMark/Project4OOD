#include <iostream>
#include "Performance.h"
#include "Venue.h"

using namespace std;

Performance::Performance(const string& name_, Venue* venue_, Date show_date_) :
	name(name_), venue(venue_), show_date(show_date_)
{
}


/*void Performance::Display() const
{
cout << "Performance: " << name << endl;
cout << show_date.Month << "/"
<< show_date.Day << "/"
<< show_date.Year << " at "
<< show_date.Hour << ":";
cout.width(2);
cout << show_date.Minute << endl;
}*/

ostream& operator << (ostream& os, const Performance* performance)
{
	os << "Performance: " << performance->GetName() << endl;
	os << performance->Show_Date() << endl;
	os << performance->GetVenue();
	return os;
}
ostream& operator << (ostream& os, const Date& show_date)
{
	os << show_date.Month << "/"
		<< show_date.Day << "/"
		<< show_date.Year << " at "
		<< show_date.Hour << ":";
	os.width(2);
	os << show_date.Minute << endl;
	return os;
}
