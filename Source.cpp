#include<iostream>
#include <string>
#include <conio.h>
#include"windows.h"
#include "Request.h"

using namespace std;

#define ENDL cout << endl;
#define PAUSE  Sleep(1500);
#define Clear system("cls");

int main() {

	int action = 0;

	string destination;
	int tripNumber;
	string surnameAndInitials;
	Date desiredDepartureDate;

	Request rq1;

	do {
		Clear
			cout << "1. Add request " << endl;
		cout << "2. Delete request " << endl;
		cout << "3. Search by trip's number and date  " << endl;
		cout << "4. Show by destination " << endl;
		cout << "5. Show requests sorted by departure dates " << endl;
		cout << "6. Exit " << endl;
		ENDL

			cout << "Enter action: ";
		cin >> action;
		ENDL
			switch (action) {

			case 1:
				cout << "Enter destination: ";
				cin >> destination;
				cout << "Enter trip number: ";
				cin >> tripNumber;
				cout << "Enter surname and initials: ";
				getline(cin, surnameAndInitials);
				cin.ignore(12345, '\n');
				cout << "Enter desired departure date: ";
				cin >> desiredDepartureDate.day;
				cin >> desiredDepartureDate.month;
				cin >> desiredDepartureDate.year;
				
				rq1.AddRequest(destination, InfoRequest(destination, tripNumber,
					surnameAndInitials, Date(desiredDepartureDate.day, desiredDepartureDate.month,
						desiredDepartureDate.year)));
				 ENDL
					cout << "Request was successfully added!" << endl;
				PAUSE
					break;
			case 2:
				if (!rq1.isEmpty()) {
					cout << "Enter request's destination you want to delete: ";
					cin >> destination;
					rq1.DelRequest(destination);
				}
				else {
					cout << "Request's list is empty!" << endl;
				}
				PAUSE
					break;
			case 3:
				if (!rq1.isEmpty()) {
				cout << "Enter desired departure date: ";
				cin >> desiredDepartureDate.day;
				cin >> desiredDepartureDate.month;
				cin >> desiredDepartureDate.year;

				cout << "Enter trip number: ";
				cin >> tripNumber;

				rq1.ShowByDateAndNum(Date(desiredDepartureDate.day, desiredDepartureDate.month,
					desiredDepartureDate.year), tripNumber);

				cout << "Enter space to continue!";
				while (_getch() != 32);
				}
				else {
					cout << "Request's list is empty!" << endl;
				}
				PAUSE
					break;
			case 4:
				if (!rq1.isEmpty()) {
				cout << "Enter request's destination you want to search: ";
				cin >> destination;
				rq1.ShowByDestination(destination);
				cout << "Enter space to continue!";
				while (_getch() != 32);
				}
				else {
					cout << "Request's list is empty!" << endl;
				}
				PAUSE
					break;
			case 5:
				if (!rq1.isEmpty()) {
				rq1.SortByDate();
				cout << "Requests were sorted by date!" << endl;
				}
				else {
					cout << "Request's list is empty!" << endl;
				}
				PAUSE
					break;
				break;
			case 6:
				break;
			default:
				cout << "Enter correct number!" << endl;
			}

	} while (action != 6);	


	/*Request rq2;
	rq2.AddRequest("Rivne", InfoRequest("Rivne", 5, "Kate", Date(17, 3, 2020)));
	rq2.AddRequest("Rivne", InfoRequest("Rivne", 5, " Bob", Date(10, 4, 2020)));
	rq2.AddRequest("Rivne", InfoRequest("Rivne", 5, "Olga", Date(15, 12, 2018)));
	rq2.AddRequest("Rivne", InfoRequest("Rivne", 5, "Pavlo", Date(17, 3, 2017)));

	rq2.SortByDate();*/

	system("pause");
	return 0;
}