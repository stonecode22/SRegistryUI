#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class student
{
public:
	student();
	~student();
	student(const char * nFirst, const char * nLast, int nID, const char* nDate, const char * nPhone, int nZip, const char * nState, const char * nCity, bool nHonors, bool nTA);
	student(student* kid);
	void displayInfo();
	friend class ll;
	friend class registry;
private:
	char* first;
	char* last;
	int id;
	char* date;
	char* phone;
	int zip;
	char* state;
	char* city;
	bool honors;
	bool TA;
	int fees;
	int* courses;
	int courseSize;
	int hours;
};