#pragma once
#include"bst.h"
#include"ll.h"
#include<string>
using namespace System;
using namespace System::Windows::Forms;

class registry
{
public:
	registry();
	~registry();
	int addStudent(student* newKid);
	int remStudent(int id);
	int displayStudents();
	student* searchStudent(int id);
	int addCourse(course* newCourse);
	int displayCourses();
	course* searchCourse(int id);
	int setCourse(int sID, int cID, ListBox^ box);
	int studentCourses(int sID);
	void save();
	int* read();
	int refreshStudent(ListBox^ box);
	int refreshCourse(ListBox^ box);
	int courseHolder(ListBox^ box, int id);
	int* idHolder(int id);
	String^ returnStudent(int id);
	String^ returnCourse(int id);
	void sortByFirst();
	void sortByLast();
	void sortByID();
private:
	ll studentList;
	bst courseTree;
	int s;
	int c;
};