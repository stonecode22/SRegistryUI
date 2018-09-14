#include"registry.h"

registry::registry()
{
	int* ids = read();
	s = ids[0];
	c = ids[1];
	cout << "Student Registry:\n";
}

registry::~registry()
{

}

int registry::addStudent(student* newKid)
{
	s++;
	newKid->id = s;
	studentList.add(newKid);
	return 1;
}

int registry::remStudent(int id)
{
	if (studentList.rem(id) == 0)
	{
		cout << "No student with that ID.\n";
	}
	else
	{
		cout << "Student #" << id << " has been successfully removed.\n";
	}
	return 1;
}

int registry::displayStudents()
{
	cout << "- - - -\n";
	studentList.display();
	return 1;
}

student* registry::searchStudent(int id)
{
	if (studentList.search(id) == NULL)
	{
		cout << "\nStudent with ID #" << id << " could not be found.\n";
		return NULL;
	}
	return studentList.search(id);
}

int registry::addCourse(course* newCourse)
{
	c++;
	newCourse->id = c;
	courseTree.add(newCourse);
	return 1;
}

int registry::displayCourses()
{
	courseTree.display();
	return 1;
}

course* registry::searchCourse(int id)
{
	if (courseTree.search(id) == NULL)
	{
		return NULL;
	}
	return courseTree.search(id);
}

int registry::setCourse(int sID, int cID, ListBox^ box)
{
	student* student = studentList.search(sID);
	course* course = courseTree.search(cID);
	if (student->courseSize == 10)
	{
		return 3;
	}
	else if ((student->hours + course->courseHours) >= 23)
	{
		return 4;
	}
	else if (student != NULL && course != NULL)
	{
		bool repeat = false;
		int cSize = student->courseSize;
		cSize++;
		for (int i = 0; i < 10; i++)
		{
			if (student->courses[i] == cID)
			{
				return 2;
				repeat = true;
				break;
			}
			if (student->courses[i] == 0)
			{
				student->courses[i] = cID;
				break;
			}
		}
		if (repeat == false)
		{
			student->courseSize = cSize;
			student->fees = (student->fees) + course->courseFee;
			student->hours = (student->hours) + course->courseHours;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int registry::studentCourses(int sID)
{
	student* student = studentList.search(sID);
	if (student == NULL)
	{
		return 0;
	}
	else
	{
		cout << "\nCourses Taking:\n";
		for (int i = 0; i < student->courseSize; i++)
		{
			cout << (i + 1) << ". " << courseTree.search(student->courses[i])->name << endl;
		}
		return 1;
	}
}

void registry::save()
{
	studentList.saveData();
	courseTree.saveData();
}

int* registry::read()
{
	int* read = new int[2];
	read[0] = studentList.readData();
	read[1] = courseTree.readData();
	return read;
}

int registry::refreshStudent(ListBox^ box)
{
	//studentList.refresh(box);
	studentList.maskRefresh(box);
	return 1;
}

int registry::refreshCourse(ListBox^ box)
{
	return courseTree.maskCourse(box);
}

int registry::courseHolder(ListBox^ box, int id)
{
	return courseTree.courseHolder(box, id);
}

int* registry::idHolder(int id)
{
	return studentList.idHolder(id);
}

String^ registry::returnStudent(int id)
{
	return studentList.returnStudent(id);
}

String^ registry::returnCourse(int id)
{
	return courseTree.returnCourse(id);
}

void registry::sortByFirst()
{
	return studentList.sortByFirst();
}

void registry::sortByLast()
{
	return studentList.sortByLast();
}

void registry::sortByID()
{
	return studentList.sortByID();
}