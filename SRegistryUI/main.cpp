/*
#include"registry.h"

student* makeStudent(int sID);
course* makeCourse(int cID);

int main()
{
registry list;
int option;
int studentOption;
int courseOption;
int studentID;
int courseID;
bool repeat = true;
bool error1 = false;
bool error2 = false;
int* readfile = list.read();
int sID = readfile[0] + 1;
int cID = readfile[1] + 1;

cout << sID << " " << cID << endl;
while (repeat == true)
{
do
{
cout << "[1]Student\n[2]Course\n[0]Exit\nEntry: ";
cin >> option;
cin.ignore();
if (option == 1)
{
do
{
cout << "\nStudent\n[1]Add\n[2]Remove\n[3]Display\n[4]Search\n[5]Enroll\n[0]Back\nEntry: ";
cin >> studentOption;
cin.ignore();
if (studentOption == 1)
{
cout << "\nStudent Add\n";
student* newStudent = makeStudent(sID);
list.addStudent(newStudent);
sID++;
error2 = false;
}
else if (studentOption == 2)
{
cout << "\nStudent Remove\nEnter student ID#: ";
cin >> studentID;
cin.ignore();
list.remStudent(studentID);
error2 = false;
}
else if (studentOption == 3)
{
cout << "\nStudent List Display\n";
list.displayStudents();
error2 = false;
}
else if (studentOption == 4)
{
cout << "\nStudent Search\nEnter student ID #: ";
cin >> studentID;
student* student = list.searchStudent(studentID);
student->displayInfo();
if (list.studentCourses(studentID) == 0)
{
cout << "\nStudent #" << studentID << " is not enrolled in any courses.\n";
}
error2 = false;
}
else if (studentOption == 5)
{
cout << "\nStudent Enroll\nEnter student ID #: ";
cin >> studentID;
cout << "\nEnter course ID #: ";
cin >> courseID;
int cNum = list.setCourse(studentID, courseID);
if (cNum == 0)
{
cout << "\nStudent or Course does not exist. Try again.\n";
}
else if (cNum == 2)
{
cout << "\nStudent is already registered in course #" << courseID << ".\n";
}
else if (cNum == 3)
{
cout << "\nStudent has reached the maximum course limit of 10.\n";
}
else if (cNum == 4)
{
cout << "\nStudent cannot exceed 22 credit hours.\n";
}
else
{
cout << "\nStudent with ID #" << studentID << " has been enrolled into course #" << courseID << ".";
}
}
else if (studentOption == 0)
{
error2 = false;
}
else
{
error2 = true;
cout << "\nNot a valid input. Try again.\n";
}
} while (error2 == true);
}
else if (option == 2)
{
do
{
cout << "\nCourse\n[1]Add\n[2]Display\n[3]Search\n[0]Back\nEntry: ";
cin >> courseOption;
if (courseOption == 1)
{
cout << "\nCourse Add\n";
course* newCourse = makeCourse(cID);
list.addCourse(newCourse);
cID++;
error2 = false;
}
else if (courseOption == 2)
{
cout << "\nCourse List Display\n";
list.displayCourses();
error2 = false;
}
else if (courseOption == 3)
{
cout << "Course Search\nEnter course ID #: ";
cin >> courseID;
course* course = list.searchCourse(courseID);
if (course == NULL)
{
cout << "\nCourse ID does not exist.\n";
}
else
{
course->display();
}
error2 = false;
}
else if (courseOption == 0)
{
error2 = false;
}
else
{
error2 = true;
}
} while (error2 == true);
}
else if (option == 0)
{
repeat = false;
}
else
{
error1 = true;
}
cout << endl;
} while (error1 == true);
}
list.save();
return 0;
}

student* makeStudent(int sID)
{
char first[20];
char last[20];
char date[9];
char phone[11];
int zip;
char state[20];
char city[20];
int honors;
bool isHonors;
int TA;
bool isTA;
bool error1 = false;

cout << "\nFirst name: ";
cin.getline(first, 20, '\n');
cout << "\nLast name: ";
cin.getline(last, 20, '\n');
cout << "\nDate of Registration: ";
cin.getline(date, 9, '\n');
cout << "\nPhone #: ";
cin.getline(phone, 11, '\n');
cout << "\nZip code: ";
cin >> zip;
cin.ignore();
cout << "\nState: ";
cin.getline(state, 20, '\n');
cout << "\nCity: ";
cin.getline(city, 20, '\n');

do
{
cout << "Honors?\n[1]Yes\n[2]No\nEntry: ";
cin >> honors;
cin.ignore();
if (honors == 1)
{
isHonors = true;
error1 = false;
}
else if (honors == 2)
{
isHonors = false;
error1 = false;
}
else
{
error1 = true;
cout << "\nNot a valid input. Try again.\n";
}
cout << endl;
} while (error1 == true);
do
{
cout << "TA?\n[1]Yes\n[2]No\nEntry: ";
cin >> TA;
cin.ignore();
if (TA == 1)
{
isTA = true;
error1 = false;
}
else if (TA == 2)
{
isTA = false;
error1 = false;
}
else
{
error1 = true;
cout << "\nNot a valid input. Try again.\n";
}
cout << endl;
} while (error1 == true);
student* newStudent = new student(first, last, sID, date, phone, zip, state, city, isHonors, isTA);
return newStudent;
}

course* makeCourse(int cID)
{
char courseName[30];
int roomNumber;
int courseFee;
int courseHours;
int schedule[7] = { 0, 0, 0, 0, 0, 0, 0 };
int time[2] = { 0, 0 };
int fromTime;
int toTime;
bool stop = false;
int day;

cout << "\nCourse Name: ";
cin.ignore();
cin.getline(courseName, 30, '\n');
cout << "\nRoom #: ";
cin >> roomNumber;
cin.ignore();
cout << "\nCourse Fee: ";
cin >> courseFee;
cin.ignore();
cout << "\nCourse Hours: ";
cin >> courseHours;
cin.ignore();
cout << "\nWhich days will this class take place?\n[1]Monday\n[2]Tuesday\n[3]Wednesday\n[4]Thursday\n[5]Friday\n[6]Saturday\n[7]Sunday\n[8]Everyday\n[9]Done\nEntry: ";
while (stop == false)
{
cin >> day;
switch (day)
{
case 1:
schedule[0] = 1;
break;
case 2:
schedule[1] = 1;
break;
case 3:
schedule[2] = 1;
break;
case 4:
schedule[3] = 1;
break;
case 5:
schedule[4] = 1;
break;
case 6:
schedule[5] = 1;
break;
case 7:
schedule[6] = 1;
break;
case 8:
for (int i = 0; i < 7; i++)
{
schedule[i] = 1;
}
break;
default:
stop = true;
break;
}
}
cout << "\nFrom what time does this class start?\nEntry: ";
cin >> fromTime;
cin.ignore();
cout << "\nTo what time does this class end?\nEntry: ";
cin >> toTime;
cin.ignore();
time[0] = fromTime;
time[1] = toTime;

course* newCourse = new course(courseName, cID, roomNumber, courseFee, courseHours, schedule, time);
return newCourse;
}
*/