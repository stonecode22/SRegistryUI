#include"student.h"

student::student()
{
	first = NULL;
	last = NULL;
	id = 0;
	date = NULL;
	phone = 0;
	zip = 0;
	state = NULL;
	city = NULL;
	honors = false;
	TA = false;
	fees = 0;
	courses = NULL;
	courseSize = 0;
	hours = 0;
}

student::~student()
{
	id = 0;
	phone = 0;
	zip = 0;
	fees = 0;
	hours = 0;
}

student::student(const char* nFirst, const char* nLast, int nID, const char* nDate, const char* nPhone, int nZip, const char* nState, const char* nCity, bool nHonors, bool nTA)
{
	first = new char[strlen(nFirst) + 1];
	strcpy(first, nFirst);
	last = new char[strlen(nLast) + 1];
	strcpy(last, nLast);
	id = nID;
	date = new char[strlen(nDate) + 1];
	strcpy(date, nDate);
	phone = new char[strlen(nPhone) + 1];
	strcpy(phone, nPhone);
	zip = nZip;
	state = new char[strlen(nState) + 1];
	strcpy(state, nState);
	city = new char[strlen(nCity) + 1];
	strcpy(city, nCity);
	honors = nHonors;
	TA = nTA;
	fees = 0;
	courses = new int[10]();
	courseSize = 0;
	hours = 0;
}

student::student(student* newKid)
{
	first = new char[strlen(newKid->first) + 1];
	strcpy(first, newKid->first);
	last = new char[strlen(newKid->last) + 1];
	strcpy(last, newKid->last);
	id = newKid->id;
	date = new char[strlen(newKid->date) + 1];
	strcpy(date, newKid->date);
	phone = new char[strlen(newKid->phone) + 1];
	strcpy(phone, newKid->phone);
	zip = newKid->zip;
	state = new char[strlen(newKid->state) + 1];
	strcpy(state, newKid->state);
	city = new char[strlen(newKid->city) + 1];
	strcpy(city, newKid->city);
	honors = newKid->honors;
	TA = newKid->TA;
	fees = newKid->fees;
	courses = new int[10]();
	courseSize = newKid->courseSize;
	for (int i = 0; i < courseSize; i++)
	{
		courses[i] = newKid->courses[i];
	}
	hours = newKid->hours;
}

void student::displayInfo()
{
	cout << "\nName:             " << first << " " << last << endl;
	cout << "ID #:             " << id;
	cout << "\nDate Registered:  ";
	cout << date;
	cout << "\nPhone #:          (";
	for (int i = 0; i < 3; i++)
	{
		cout << phone[i];
	}
	cout << ")";
	for (int i = 3; i < 6; i++)
	{
		cout << phone[i];
	}
	cout << "-";
	for (int i = 6; i < 10; i++)
	{
		cout << phone[i];
	}
	cout << endl;
	cout << "Zip Code:         " << zip << endl;
	cout << "Location:         " << city << ", " << state << endl;

	if (honors == false)
	{
		cout << "Honors:           N" << endl;
	}
	else
	{
		cout << "Honors:           Y" << endl;
	}

	if (TA == false)
	{
		cout << "TA:               N" << endl;
	}
	else
	{
		cout << "TA:               Y" << endl;
	}

	cout << "Total Fees:       " << fees << endl;
	if (courseSize > 0)
	{
		cout << "Total Courses:    " << courseSize << endl;
	}
	else
	{
		cout << "Total Courses:    N/A" << endl;
	}
	cout << "Total Hours:      " << hours << endl;
}
