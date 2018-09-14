#pragma once
#include"registry.h"
#include"studentForm.h"
#include"courseForm.h"
#include"AddStudent.h"
#include"AddCourse.h"
#include<iostream>
using namespace std;

namespace SRegistryUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			courseForm courseInfo;
			
			list = new registry;
			list->refreshStudent(listBox1);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			list->save();
		}
		registry* list;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  buttonsAdd;

	private: System::Windows::Forms::Button^  buttonCourses;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonsRem;
	private: System::Windows::Forms::Button^  buttoncAdd;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->buttonsAdd = (gcnew System::Windows::Forms::Button());
			this->buttonCourses = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonsRem = (gcnew System::Windows::Forms::Button());
			this->buttoncAdd = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(28, 135);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(818, 446);
			this->listBox1->TabIndex = 0;
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::listBox1_DoubleClick);
			// 
			// buttonsAdd
			// 
			this->buttonsAdd->Location = System::Drawing::Point(49, 61);
			this->buttonsAdd->Name = L"buttonsAdd";
			this->buttonsAdd->Size = System::Drawing::Size(136, 34);
			this->buttonsAdd->TabIndex = 1;
			this->buttonsAdd->Text = L"Add Student";
			this->buttonsAdd->UseVisualStyleBackColor = true;
			this->buttonsAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonsAdd_Click);
			// 
			// buttonCourses
			// 
			this->buttonCourses->Location = System::Drawing::Point(521, 62);
			this->buttonCourses->Name = L"buttonCourses";
			this->buttonCourses->Size = System::Drawing::Size(147, 33);
			this->buttonCourses->TabIndex = 2;
			this->buttonCourses->Text = L"Courses";
			this->buttonCourses->UseVisualStyleBackColor = true;
			this->buttonCourses->Click += gcnew System::EventHandler(this, &MyForm::buttonCourses_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(319, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 50);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Student Registry";
			// 
			// buttonsRem
			// 
			this->buttonsRem->Location = System::Drawing::Point(201, 61);
			this->buttonsRem->Name = L"buttonsRem";
			this->buttonsRem->Size = System::Drawing::Size(136, 34);
			this->buttonsRem->TabIndex = 4;
			this->buttonsRem->Text = L"Remove Student";
			this->buttonsRem->UseVisualStyleBackColor = true;
			this->buttonsRem->Click += gcnew System::EventHandler(this, &MyForm::buttonsRem_Click);
			// 
			// buttoncAdd
			// 
			this->buttoncAdd->Location = System::Drawing::Point(685, 62);
			this->buttoncAdd->Name = L"buttoncAdd";
			this->buttoncAdd->Size = System::Drawing::Size(147, 33);
			this->buttoncAdd->TabIndex = 5;
			this->buttoncAdd->Text = L"Add Course";
			this->buttoncAdd->UseVisualStyleBackColor = true;
			this->buttoncAdd->Click += gcnew System::EventHandler(this, &MyForm::buttoncAdd_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(49, 106);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Sort By First Name";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(201, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Sort By Last Name";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(356, 106);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(136, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Sort By ID";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 614);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->buttoncAdd);
			this->Controls->Add(this->buttonsRem);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonCourses);
			this->Controls->Add(this->buttonsAdd);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"Student Registry";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
		if(listBox1->SelectedItems->Count > 0)
		{
			String^ info = listBox1->SelectedItem->ToString();
			info = info->Substring(1, info->IndexOf(" "));
			int id = System::Convert::ToInt32(info);
			studentForm studentInfo(list->returnStudent(id), list);
			studentInfo.ShowDialog();
		}
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void buttonsAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		AddStudent addWindow;
		addWindow.ShowDialog();
		if (addWindow.complete() == true)
		{
			char* first = (char*)Marshal::StringToHGlobalAnsi(addWindow.first).ToPointer();
			char* last = (char*)Marshal::StringToHGlobalAnsi(addWindow.last).ToPointer();
			char* date = (char*)Marshal::StringToHGlobalAnsi(addWindow.date).ToPointer();
			char* phone = (char*)Marshal::StringToHGlobalAnsi(addWindow.phone).ToPointer();
			char* state = (char*)Marshal::StringToHGlobalAnsi(addWindow.state).ToPointer();
			char* city = (char*)Marshal::StringToHGlobalAnsi(addWindow.city).ToPointer();
			int zip = addWindow.zip;
			bool honors = addWindow.honors;
			bool TA = addWindow.TA;
			int id = 0;
			student* newStudent = new student(first, last, id, date, phone, zip, state, city, honors, TA);
			list->addStudent(newStudent);
			list->displayStudents();
			list->refreshStudent(listBox1);
		}
	}
	private: System::Void buttonsRem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ info = listBox1->SelectedItem->ToString();
		info = info->Substring(1, info->IndexOf(" "));
		int sID = System::Convert::ToInt32(info);
		studentForm studentInfo(list->returnStudent(sID), list);
		list->remStudent(sID);
		list->refreshStudent(listBox1);
	}
	private: System::Void buttonCourses_Click(System::Object^  sender, System::EventArgs^  e) {
		courseForm courseInfo(list);
		courseInfo.ShowDialog();
	}
private: System::Void buttoncAdd_Click(System::Object^  sender, System::EventArgs^  e) {
	AddCourse addInfo;
	addInfo.ShowDialog();
	if (addInfo.complete() == true)
	{
		char* name = (char*)Marshal::StringToHGlobalAnsi(addInfo.name).ToPointer();
		int roomNumber = addInfo.roomNumber;
		int courseFee = addInfo.fee;
		int courseHours = addInfo.cred;
		String^ origTime = addInfo.time;
		int time[2];
		time[0] = Int32::Parse(origTime->Substring(0, origTime->IndexOf(" ")));
		origTime = origTime->Remove(0, origTime->IndexOf(" "));
		time[1] = Int32::Parse(origTime);
		String^ origSchedule = addInfo.schedule;
		int schedule[7];
		for (int i = 0; i < 7; i++)
		{
			schedule[i] = Int32::Parse(origSchedule->Substring(i, 1));
		}
		int id = 0;
		course* newCourse = new course(name, id, roomNumber, courseFee, courseHours, schedule, time);
		list->addCourse(newCourse);
		list->displayCourses();
		addInfo.refreshCourse(list);
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	list->sortByFirst();
	list->refreshStudent(listBox1);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	list->sortByLast();
	list->refreshStudent(listBox1);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	list->sortByID();
	list->refreshStudent(listBox1);
}
};
}
