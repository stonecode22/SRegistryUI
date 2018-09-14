#pragma once
#include"course.h"
using namespace System;
using namespace System::Windows::Forms;

struct nodeC
{
	course* c;
	nodeC* left;
	nodeC* right;
};

class bst
{
public:
	bst();
	~bst();
	int add(course* c);
	void display();
	void removeAll();
	course* search(int id);
	void saveData();
	int readData();
	int refresh(ListBox^ box);
	int maskCourse(ListBox^ box);
	int courseHolder(ListBox^ box, int id);
	String^ returnCourse(int id);
private:
	int add(nodeC* &head, course* cl);
	void display(nodeC* head);
	void removeAll(nodeC* &head);
	course* search(nodeC* head, int id);
	void saveData(nodeC* head, ofstream& fileOut);
	int refresh(nodeC* head, ListBox^ box);
	int maskCourse(nodeC* head, ListBox^ box);
	int courseHolder(nodeC* head, ListBox^ box, int id);
	String^ returnCourse(nodeC* head, int id);
	nodeC* head;
};