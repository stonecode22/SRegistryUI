#include"ll.h"
#include<string>

ll::ll()
{
	head = NULL;
}

ll::~ll()
{
	while (head != NULL)
	{
		node* temp = head->next;
		delete head;
		head = NULL;
		head = temp;
	}
}

int ll::add(student* newKid)
{
	return add(head, newKid);
}

int ll::add(node* &head, student* newKid)
{
	if (head == NULL)
	{
		node* newNode = new node;
		newNode->kid = new student(newKid);
		newNode->next = NULL;
		head = newNode;
		return 1;
	}
	else
	{
		return add(head->next, newKid);
	}
}

int ll::rem(int id)
{
	return rem(head, id);
}

int ll::rem(node* &head, int id)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		if (head->kid->id == id)
		{
			node* temp = head->next;
			delete head;
			head = NULL;
			head = temp;
			return 1;
		}
		else
		{
			return rem(head->next, id);
		}
	}
}

void ll::display()
{
	return display(head);
}

void ll::display(node* head)
{
	if (head != NULL)
	{
		head->kid->displayInfo();
		cout << endl;
		return display(head->next);
	}
	else
	{
		return;
	}
}

student* ll::search(int id)
{
	return search(head, id);
}

student* ll::search(node* head, int id)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		if (head->kid->id == id)
		{
			return (head->kid);
		}
		else
		{
			return search(head->next, id);
		}
	}
}


void ll::saveData()
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		node* temp = head;
		ofstream fileOut;
		fileOut.open("students.txt");
		while (temp != NULL)
		{
			fileOut << temp->kid->first << " ";
			fileOut << temp->kid->last << " ";
			fileOut << temp->kid->id << " ";
			fileOut << temp->kid->date << " ";
			fileOut << temp->kid->phone << " ";
			fileOut << temp->kid->zip << " ";
			fileOut << temp->kid->state << ",";
			fileOut << temp->kid->city << ",";
			fileOut << temp->kid->honors << " ";
			fileOut << temp->kid->TA << " ";
			fileOut << temp->kid->fees << " ";
			fileOut << temp->kid->courseSize << " ";
			for (int i = 0; i < temp->kid->courseSize; i++)
			{
				fileOut << temp->kid->courses[i] << " ";
			}
			fileOut << temp->kid->hours << endl;
			temp = temp->next;
		}
		fileOut.close();
	}
}

int ll::readData()
{
	fstream fileIn;
	fileIn.open("students.txt");
	char first[20];
	if (fileIn)
	{
		fileIn.get(first, 20, ' ');
		fileIn.ignore(20, ' ');
	}
	while (fileIn && !fileIn.eof())
	{
		char last[20];
		char date[11];
		char phone[11];
		int zip;
		int id;
		char state[20];
		char city[20];
		int honors;
		bool isHonors;
		int TA;
		bool isTA;
		int fees;
		int courseSize;
		int courses[10];
		int hours;

		fileIn.get(last, 20, ' ');
		fileIn.ignore(20, ' ');
		fileIn >> id;
		fileIn.ignore();
		fileIn.get(date, 11, ' ');
		fileIn.ignore(11, ' ');
		fileIn.get(phone, 11, ' ');
		fileIn.ignore(11, ' ');
		fileIn >> zip;
		fileIn.ignore();
		fileIn.get(state, 20, ',');
		fileIn.ignore(20, ',');
		fileIn.get(city, 20, ',');
		fileIn.ignore(20, ',');
		fileIn >> honors;
		fileIn.ignore();
		if (honors == 1)
		{
			isHonors = true;
		}
		else
		{
			isHonors = false;
		}
		fileIn >> TA;
		fileIn.ignore();
		if (TA == 1)
		{
			isTA = true;
		}
		else
		{
			isTA = false;
		}
		student* newStudent = new student(first, last, id, date, phone, zip, state, city, isHonors, isTA);
		fileIn >> fees;
		fileIn.ignore();
		fileIn >> courseSize;
		fileIn.ignore();
		for (int i = 0; i < courseSize; i++)
		{
			fileIn >> courses[i];
		}
		fileIn >> hours;
		fileIn.ignore();
		newStudent->fees = fees;
		newStudent->courseSize = courseSize;
		newStudent->courses = courses;
		newStudent->hours = hours;
		add(newStudent);
		fileIn.get(first, 20, ' ');
		fileIn.ignore(20, ' ');
	}
	fileIn.close();
	fileIn.clear();
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		int value = temp->kid->id;
		return value;
	}
}

int ll::sizeOf()
{
	int size = 0;
	node* temp = head;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

int ll::refresh(ListBox^ box)
{
	box->Items->Clear();
	node* temp = head;
	int size = sizeOf() + 1;
	cout << "Size: " << size << endl;
	while(temp != NULL)
	{
		if (temp->kid != NULL)
		{
			string firstName(temp->kid->first);
			string lastName(temp->kid->last);
			string id = to_string(temp->kid->id);
			string date(temp->kid->date);
			string phone(temp->kid->phone);
			string state(temp->kid->state);
			string city(temp->kid->city);
			string honors = to_string(temp->kid->honors);
			string TA = to_string(temp->kid->TA);
			string fees = to_string(temp->kid->fees);
			string courseSize = to_string(temp->kid->courseSize);
			string hours = to_string(temp->kid->hours);
			//string names = id + " " + firstName + " " + lastName;
			string data = "[" + firstName + "][" + lastName + "][" + id + "][" + date + "][" + phone + "][" + state + "][" + city + "][" + honors + "][" + TA + "][" + fees + "][" + courseSize + "][" + hours + "]";
			box->Items->Add(gcnew String(data.c_str()));
		}
		temp = temp->next;
	}
	return 1;
}

int ll::maskRefresh(ListBox^ box)
{
	box->Items->Clear();
	node* temp = head;
	int size = sizeOf() + 1;
	cout << "Size: " << size << endl;
	while (temp != NULL)
	{
		if (temp->kid != NULL)
		{
			string firstName(temp->kid->first);
			string lastName(temp->kid->last);
			string id = to_string(temp->kid->id);
			string date(temp->kid->date);
			string phone(temp->kid->phone);
			string state(temp->kid->state);
			string city(temp->kid->city);
			string honors = to_string(temp->kid->honors);
			string TA = to_string(temp->kid->TA);
			string fees = to_string(temp->kid->fees);
			string courseSize = to_string(temp->kid->courseSize);
			string hours = to_string(temp->kid->hours);
			string data = "#" + id + " " + firstName + " " + lastName;
			box->Items->Add(gcnew String(data.c_str()));
		}
		temp = temp->next;
	}
	return 1;
}

String^ ll::returnStudent(int id)
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->kid->id == id)
		{
			string firstName(temp->kid->first);
			string lastName(temp->kid->last);
			string id = to_string(temp->kid->id);
			string date(temp->kid->date);
			string phone(temp->kid->phone);
			string state(temp->kid->state);
			string city(temp->kid->city);
			string honors = to_string(temp->kid->honors);
			string TA = to_string(temp->kid->TA);
			string fees = to_string(temp->kid->fees);
			string courseSize = to_string(temp->kid->courseSize);
			string hours = to_string(temp->kid->hours);
			string all = "[" + firstName + "][" + lastName + "][" + id + "][" + date + "][" + phone + "][" + state + "][" + city + "][" + honors + "][" + TA + "][" + fees + "][" + courseSize + "][" + hours + "]";
			return (gcnew String(all.c_str()));
		}
		else
		{
			temp = temp->next;
		}
	}
}

int* ll::idHolder(int id)
{
	node* temp = head;
	int* store = new int[10]();
	while (temp != NULL)
	{
		if (temp->kid->id == id)
		{
			for (int i = 0; i < 10; i++)
			{
				store[i] = temp->kid->courses[i];
			}
			return store;
		}
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

void ll::sortByFirst()
{
	for (int i = 0; i < sizeOf(); i++)
	{
		sortByFirst(head);
	}
	return;
}

void ll::sortByFirst(node* &head)
{
	if(head != NULL)
	{
		if (head->next != NULL)
		{
			int sum1 = 0;
			int sum2 = 0;
			int finalSize = 1;
			char name1;
			char name2;
			bool slide = true;

			while (slide == true)
			{
				for (int i = 0; i < finalSize; i++)
				{
					name1 = head->kid->first[i];
					sum1 = sum1 + (int)name1;
				}
				for (int i = 0; i < finalSize; i++)
				{
					name2 = head->next->kid->first[i];
					sum2 = sum2 + (int)name2;
				}
				if (sum1 == sum2)
				{
					slide = true;
					finalSize++;
				}
				else
				{
					slide = false;
				}
			}

			if (sum1 >= sum2)
			{
				node* save = head->next;
				head->next = save->next;
				save->next = head;
				head = save;
				return sortByFirst(head->next);
			}
			else
			{
				return sortByFirst(head->next);
			}
		}
		else
		{
			return;
		}
	}
}

void ll::sortByLast()
{
	for (int i = 0; i < sizeOf(); i++)
	{
		sortByLast(head);
	}
	return;
}

void ll::sortByLast(node* &head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			int sum1 = 0;
			int sum2 = 0;
			int finalSize = 1;
			char name1;
			char name2;
			bool slide = true;

			while (slide == true)
			{
				for (int i = 0; i < finalSize; i++)
				{
					name1 = head->kid->last[i];
					sum1 = sum1 + (int)name1;
				}
				for (int i = 0; i < finalSize; i++)
				{
					name2 = head->next->kid->last[i];
					sum2 = sum2 + (int)name2;
				}
				if (sum1 == sum2)
				{
					slide = true;
					finalSize++;
				}
				else
				{
					slide = false;
				}
			}

			if (sum1 >= sum2)
			{
				node* save = head->next;
				head->next = save->next;
				save->next = head;
				head = save;
				return sortByLast(head->next);
			}
			else
			{
				return sortByLast(head->next);
			}
		}
		else
		{
			return;
		}
	}
}

void ll::sortByID()
{
	for (int i = 0; i < sizeOf(); i++)
	{
		sortByID(head);
	}
	return;
}

void ll::sortByID(node* &head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			int sum1 = head->kid->id;
			int sum2 = head->next->kid->id;
			if (sum1 > sum2)
			{
				node* save = head->next;
				head->next = save->next;
				save->next = head;
				head = save;
				return sortByID(head->next);
			}
			else
			{
				return sortByID(head->next);
			}
		}
		else
		{
			return;
		}
	}
}