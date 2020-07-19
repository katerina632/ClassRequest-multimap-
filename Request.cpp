#include "Request.h"

bool operator==(const Date& d1, const Date& d2)
{
	return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

bool operator<(const Date& d1, const Date& d2)
{
	return  (d1.year < d2.year ||
		d1.year == d2.year &&
		d1.month < d2.month ||
		d1.year == d2.year &&
		d1.month == d2.month &&
		d1.day < d2.day);
}

ostream& operator<<(ostream& os, const InfoRequest& rq)
{
	os << "Destination" << rq.destination << endl;
	os << "Trip number: " << rq.tripNumber << endl;
	os << "Surname and initials: " << rq.surnameAndInitials << endl;
	os << "Date: " << rq.desiredDepartureDate.day << "." <<
		rq.desiredDepartureDate.month << "." << rq.desiredDepartureDate.year << endl;
	cout << endl;
	return os;
}

bool operator==(const InfoRequest& if1, const InfoRequest& if2)
{
	return if1.destination == if2.destination && if1.tripNumber == if2.tripNumber && if1.desiredDepartureDate == if2.desiredDepartureDate &&
		if1.surnameAndInitials == if2.surnameAndInitials;
}

void Request::AddRequest(string destination, InfoRequest info)
{
	requests.insert(make_pair(destination, info));
}

void Request::DelRequest(string imput)
{
	if (requests.find(imput) == requests.end())
		cout << "Request not found!\n";
	else
	{
		requests.erase(imput);
	}
}

void Request::ShowByDestination(string des) const{

	auto iter = requests.find(des);

	if(iter== requests.end())
		cout << "Request not found!\n";
	else
	{
		while (iter != requests.end())
		{
			cout << "Destination: " << (*iter).first << endl;
			cout << "Requests:" << (*iter).second << endl;
			++iter;
		}
	}
}

void Request::ShowByDateAndNum(Date t, int num) const
{
	for (auto i = requests.begin(); i != requests.end(); ++i)
	{
		if (i->second.desiredDepartureDate == t && i->second.tripNumber == num) {
			cout << "Destination: " << i->first << endl;
			cout << "Requests:" << i->second << endl;
		}
		else {
			cout << "Request not found!\n";
		}
	}
}

void Request::SortByDate()
{
	typedef pair<string, InfoRequest>pair;
	vector<pair>vec;
	copy(requests.begin(), requests.end(), back_inserter<vector<pair>>(vec));
	sort(vec.begin(), vec.end(), [](const pair& l, const pair& r) {if (!(l.second == r.second)) return l.second.desiredDepartureDate < r.second.desiredDepartureDate; return l.first < r.first; });
	for (auto i : vec) {
		cout << i.first << endl << i.second << endl;
	}
}
