#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include<algorithm>
#include <list>

using namespace std;

struct Date {
	int day;
	int month;
	int year;

	Date() : day(0), month(0), year(0) {}
	Date(int day,int month, int year) : day(day), month(month), year(year) {}	

	friend bool operator==(const Date& d1, const Date& d2);

	friend bool operator<(const Date& d1, const Date& d2);
	
};

struct InfoRequest {
	string destination;
	int tripNumber;
	string surnameAndInitials;
	Date desiredDepartureDate;

	InfoRequest() : destination("No destination"), tripNumber(0), surnameAndInitials("No Initials"), desiredDepartureDate(1, 1, 1) {}
	InfoRequest(string destination, int num, string surname, Date date) 
		: destination(destination), tripNumber(num), surnameAndInitials(surname), desiredDepartureDate(date) {}

	friend ostream& operator<<(ostream& os, const InfoRequest& rq);
	
	friend bool operator==(const InfoRequest& if1, const InfoRequest& if2);
};


class Request
{
	multimap<string, InfoRequest> requests;

	
public:
	Request() {}	

	inline bool isEmpty() {
		return requests.empty();
	}
	

	void AddRequest(string destination, InfoRequest info);
	void DelRequest(string  imput);

	void ShowByDestination(string des) const;

	void ShowByDateAndNum(Date t, int num) const;

	void SortByDate();
};

