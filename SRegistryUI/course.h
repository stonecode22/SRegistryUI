#pragma once
#include"student.h"

class course
{
public:
	course();
	~course();
	course(const char* nName, int nID, int roomNumber, int nCourseFee, int nCourseHours, int* nSchedule, int* nTime);
	course(course* copy);
	void display();
	friend class bst;
	friend class registry;
private:
	char* name;
	int roomNumber;
	int id;
	int courseFee;
	int courseHours;
	int* schedule;
	int* time;
};