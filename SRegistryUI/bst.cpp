#include "bst.h"
#include<string>

bst::bst()
{
	head = NULL;
}

bst::~bst()
{
	removeAll();
}


void bst::removeAll()
{
	return removeAll(head);
}

void bst::removeAll(nodeC* &head)
{
	if (head != NULL)
	{
		removeAll(head->right);
		removeAll(head->left);
		delete head;
		head = NULL;
	}
}

int bst::add(course* cl)
{
	return add(head, cl);
}

int bst::add(nodeC* &head, course* cl)
{
	if (head == NULL)
	{
		nodeC* newNode = new nodeC;
		newNode->c = new course(cl);
		newNode->left = NULL;
		newNode->right = NULL;
		head = newNode;
		return 1;
	}
	else if (cl->id < head->c->id)
	{
		return add(head->left, cl);
	}
	else
	{
		return add(head->right, cl);
	}
}

void bst::display()
{
	return display(head);
}

void bst::display(nodeC* head)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		display(head->left);
		head->c->display();
		cout << endl;
		display(head->right);
	}
}

course* bst::search(int id)
{
	return search(head, id);
}

course* bst::search(nodeC* head, int id)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		if (head->c->id == id)
		{
			return (head->c);
		}
		else if (id > head->c->id)
		{
			return search(head->right, id);
		}
		else
		{
			return search(head->left, id);
		}
	}
}

void bst::saveData()
{
	ofstream fileOut;
	fileOut.open("courses.txt");
	saveData(head, fileOut);
	fileOut.close();
}

void bst::saveData(nodeC* head, ofstream& fileOut)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		fileOut << head->c->name << ", ";
		fileOut << head->c->id << " ";
		fileOut << head->c->roomNumber << " ";
		fileOut << head->c->courseFee << " ";
		fileOut << head->c->courseHours << " ";
		for (int i = 0; i < 7; i++)
		{
			fileOut << head->c->schedule[i] << " ";
		}
		fileOut << head->c->time[0] << " ";
		fileOut << head->c->time[1] << endl;
		saveData(head->left, fileOut);
		saveData(head->right, fileOut);
	}
}

int bst::readData()
{
	fstream fileIn;
	fileIn.open("courses.txt");
	char name[30];
	if (fileIn)
	{
		fileIn.get(name, 30, ',');
		fileIn.ignore(30, ',');
	}
	while (fileIn && !fileIn.eof())
	{
		int id;
		int roomNumber;
		int courseFee;
		int courseHours;
		int schedule[7];
		int time[2];

		fileIn >> id;
		fileIn.ignore();
		fileIn >> roomNumber;
		fileIn.ignore();
		fileIn >> courseFee;
		fileIn.ignore();
		fileIn >> courseHours;
		fileIn.ignore();
		for (int i = 0; i < 7; i++)
		{
			fileIn >> schedule[i];
		}
		fileIn >> time[0];
		fileIn.ignore();
		fileIn >> time[1];
		fileIn.ignore();
		course* newCourse = new course(name, id, roomNumber, courseFee, courseHours, schedule, time);
		add(newCourse);
		fileIn.get(name, 30, ',');
		fileIn.ignore(30, ',');
	}
	fileIn.close();
	fileIn.clear();
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		nodeC* temp = head;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		int value = temp->c->id;
		return value;
	}
}


int bst::refresh(ListBox^ box)
{
	box->Items->Clear();
	return refresh(head, box);
}

int bst::refresh(nodeC* head, ListBox^ box)
{
	if (head == NULL)
	{
		return 0;
	}
	else if (head != NULL)
	{
		refresh(head->left, box);
		string name(head->c->name);
		string roomNumber = to_string(head->c->roomNumber);
		string id = to_string(head->c->id);
		string cFees = to_string(head->c->courseFee);
		string cHours = to_string(head->c->courseHours);
		string schedule;
		for (int i = 0; i < 7; i++)
		{
			schedule = schedule + to_string(head->c->schedule[i]);
		}
		string time;
		for (int i = 0; i < 2; i++)
		{
			time = time + to_string(head->c->time[i]);
		}
		string data = "[" + name + "][" + id + "][" + roomNumber + "][" + cFees + "][" + cHours + "][" + schedule + "}{" + time + "}";
		box->Items->Add(gcnew String(data.c_str()));
		refresh(head->right, box);
		return 1;
	}
}

int bst::maskCourse(ListBox^ box)
{
	box->Items->Clear();
	return maskCourse(head, box);
}

int bst::maskCourse(nodeC* head, ListBox^ box)
{
	if (head == NULL)
	{
		return 0;
	}
	else if (head != NULL)
	{
		maskCourse(head->left, box);
		string name(head->c->name);
		string roomNumber = to_string(head->c->roomNumber);
		string id = to_string(head->c->id);
		string cFees = to_string(head->c->courseFee);
		string cHours = to_string(head->c->courseHours);
		string schedule;
		for (int i = 0; i < 7; i++)
		{
			schedule = schedule + to_string(head->c->schedule[i]);
		}
		string time;
		for (int i = 0; i < 2; i++)
		{
			time = time + to_string(head->c->time[i]);
		}
		string data = "#" + id + " "+ name + " [" + roomNumber + "]";
		box->Items->Add(gcnew String(data.c_str()));
		maskCourse(head->right, box);
		return 1;
	}
}

int bst::courseHolder(ListBox^ box, int id)
{
	return courseHolder(head, box, id);
}

int bst::courseHolder(nodeC* head, ListBox^ box, int id)
{
	if (head == NULL)
	{
		return 0;
	}
	else if (head != NULL)
	{
		courseHolder(head->left, box, id);
		if (head->c->id == id)
		{
			string name(head->c->name);
			string roomNumber = to_string(head->c->roomNumber);
			string id = to_string(head->c->id);
			string data = "#" + id + " " + name + " [" + roomNumber + "]";
			box->Items->Add(gcnew String(data.c_str()));
			return 1;
		}
		return courseHolder(head->right, box, id);
	}
}

String^ bst::returnCourse(int id)
{
	return returnCourse(head, id);
}

String^ bst::returnCourse(nodeC* head, int id)
{
	if (head != NULL)
	{
		if (head->c->id == id)
		{
			string name(head->c->name);
			string roomNumber = to_string(head->c->roomNumber);
			string id = to_string(head->c->id);
			string cFees = to_string(head->c->courseFee);
			string cHours = to_string(head->c->courseHours);
			string schedule;
			for (int i = 0; i < 7; i++)
			{
				schedule = schedule + to_string(head->c->schedule[i]);
			}
			string time;
			for (int i = 0; i < 2; i++)
			{
				time = time + to_string(head->c->time[i]);
			}
			string data = "[" + name + "][" + id + "][" + roomNumber + "][" + cFees + "][" + cHours + "][" + schedule + "}{" + time + "}";
			return (gcnew String(data.c_str()));
		}
		else if (head->c->id < id)
		{
			return returnCourse(head->left, id);
		}
		else
		{
			return returnCourse(head->right, id);
		}
	}
	return "0";
}