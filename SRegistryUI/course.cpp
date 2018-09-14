#include"course.h"

course::course()
{
	name = NULL;
	id = 0;
	courseFee = 0;
	courseHours = 0;
	schedule = NULL;
	time = NULL;
	roomNumber = 0;
}

course::~course()
{
	id = 0;
	courseFee = 0;
	courseHours = 0;
	roomNumber = 0;
}

course::course(const char * nName, int nID, int nRoomNumber, int nCourseFee, int nCourseHours, int* nSchedule, int* nTime)
{
	name = new char[strlen(nName) + 1];
	strcpy(name, nName);
	id = nID;
	roomNumber = nRoomNumber;
	courseFee = nCourseFee;
	courseHours = nCourseHours;
	schedule = new int[7]();
	for (int i = 0; i < 7; i++)
	{
		schedule[i] = nSchedule[i];
	}
	time = new int[2];
	for (int i = 0; i < 2; i++)
	{
		time[i] = nTime[i];
	}
}

course::course(course* copy)
{
	name = new char[strlen(copy->name) + 1];
	strcpy(name, copy->name);
	id = copy->id;
	roomNumber = copy->roomNumber;
	courseFee = copy->courseFee;
	courseHours = copy->courseHours;
	schedule = new int[7]();
	for (int i = 0; i < 7; i++)
	{
		schedule[i] = copy->schedule[i];
	}
	time = new int[2];
	for (int i = 0; i < 2; i++)
	{
		time[i] = copy->time[i];
	}
}

void course::display()
{
	cout << "Class Name:   " << name << endl;
	cout << "ID #:         " << id << endl;
	cout << "Room #:       " << roomNumber << endl;
	cout << "Cost:         " << courseFee << endl;
	cout << "Credit Hours: " << courseHours << endl;
	cout << "Classes on:   ";
	for (int i = 0; i < 7; i++)
	{
		if (schedule[i] != 0)
		{
			switch (i)
			{
			case 0:
				cout << "M ";
				break;
			case 1:
				cout << "T ";
				break;
			case 2:
				cout << "W ";
				break;
			case 3:
				cout << "Th ";
				break;
			case 4:
				cout << "F ";
				break;
			case 5:
				cout << "Sa ";
				break;
			case 6:
				cout << "Su ";
				break;
			default:
				break;
			}
		}
	}
	cout << "\nHours:        ";
	cout << time[0] << " to " << time[1] << endl;
}

