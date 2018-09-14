#pragma once
#include"student.h"
using namespace System;
using namespace System::Windows::Forms;

struct node
{
	student* kid;
	node* next;
};

class ll
{
public:
	ll();
	~ll();
	int add(student* newKid);
	int rem(int id);
	void display();
	student* search(int id);
	void saveData();
	int readData();
	int sizeOf();
	int refresh(ListBox^ box);
	int maskRefresh(ListBox^ box);
	int* idHolder(int id);
	void sortByFirst();
	void sortByLast();
	void sortByID();
	String^ returnStudent(int id);
private:
	node * head;
	int add(node* &head, student* newKid);
	int rem(node* &head, int id);
	void display(node* head);
	void sortByFirst(node* &head);
	void sortByLast(node* &head);
	void sortByID(node* & head);
	student* search(node* head, int id);
};