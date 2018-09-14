#pragma once
#include"registry.h"

namespace SRegistryUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for studentForm
	/// </summary>
	public ref class studentForm : public System::Windows::Forms::Form
	{
	public:
		studentForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		studentForm(String^ data, registry* reg)
		{
			InitializeComponent();
			list = reg;
			list->refreshCourse(listBox2);
			String^ copy(data);

			int startIndex = copy->IndexOf("[");
			int endIndex = copy->IndexOf("]");
			int length = (endIndex+1) - (startIndex);

			first = copy->Substring(startIndex+1, length-2);
			copy = copy->Remove(0, length);

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			last = copy->Substring(startIndex+1, length-2);
			copy = copy->Remove(startIndex+1, length);
			label1->Text = "Name: " + first + " " + last;

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			id = copy->Substring(startIndex+1, length-2);
			sID = Convert::ToInt32(id);
			copy = copy->Remove(startIndex+1, length);
			label2->Text = "ID:   " + id;

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			date = copy->Substring(startIndex+1, length-2);
			copy = copy->Remove(startIndex+1, length);
			label3->Text = "Date: " + date;

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			phone = copy->Substring(startIndex+1, length-2);
			copy = copy->Remove(startIndex+1, (length));
			label4->Text = "Phone:    " + phone;

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			state = copy->Substring(startIndex+1, length-2);
			copy = copy->Remove(startIndex+1, (length));
			

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			city = copy->Substring(startIndex+1, length-2);
			copy = copy->Remove(startIndex+1, (length));
			label5->Text = "Location: " + city + ", " + state;

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			honors = copy->Substring(startIndex+1, length-2);
			int isHonors = Convert::ToInt32(honors);
			copy = copy->Remove(startIndex+1, length);
			if (isHonors == 1)
			{
				label6->Text = "Honors:   Y";
			}
			else
			{
				label6->Text = "Honors:   N";
			}

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			TA = copy->Substring(startIndex+1, length-2);
			int isTA = Convert::ToInt32(TA);
			copy = copy->Remove(startIndex+1, length);
			if (isTA == 1)
			{
				label7->Text = "TA:          Y";
			}
			else
			{
				label7->Text = "TA:          N";
			}

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			courseSize = copy->Substring(startIndex+1, length-2);
			int size = Convert::ToInt32(courseSize);
			copy = copy->Remove(startIndex+1, (length));

			startIndex = copy->IndexOf("[");
			endIndex = copy->IndexOf("]");
			length = (endIndex+1)-(startIndex);
			hours = copy->Substring(startIndex+1, length-2);

			idList();
		}
		void idList()
		{
			int* store = new int[10]();
			store = list->idHolder(sID);
			for (int i = 0; i < 10; i++)
			{
				if (store[i] != 0)
				{
					list->courseHolder(listBox1, store[i]);
				}
			}
		}
		String^ first;
		String^ last;
		String^ id;
		int sID;
		String^ date;
		String^ phone;
		String^ state;
		String^ city;
		String^ honors;
		String^ TA;
		String^ courseSize;
		registry* list;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label7;
	public:
		String ^ hours;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~studentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  listBox2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(158, 528);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Enroll Into Classes";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &studentForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(25, 144);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(315, 355);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &studentForm::listBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Name: ";
			this->label1->Click += gcnew System::EventHandler(this, &studentForm::label1_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(356, 144);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(328, 355);
			this->listBox2->TabIndex = 3;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &studentForm::listBox2_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"ID:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Date: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(353, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Phone: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(353, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Location:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(353, 73);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Honors: ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(353, 96);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"TA: ";
			// 
			// studentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 576);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"studentForm";
			this->Text = L"studentForm";
			this->Load += gcnew System::EventHandler(this, &studentForm::studentForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void studentForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ data = listBox2->SelectedItem->ToString();
	String^ hold = listBox2->SelectedItem->ToString();
	Console::WriteLine(data);
	data = data->Substring(1, data->IndexOf(" "));
	Console::WriteLine(data);
	int id1 = System::Convert::ToInt32(data);
	int result = list->setCourse(sID, id1, listBox1);
	if(result == 3)
	{
		Console::WriteLine("Already assigned 10 classes!");
	}
	else if (result == 4)
	{
		Console::WriteLine("Too many credits!");
	}
	else if (result == 2)
	{
		Console::WriteLine("You are already enrolled in this class!");
	}
	else
	{
		if (listBox2->SelectedItems->Count > 0)
		{
			listBox1->Items->Clear();
			idList();
		}
	}

}
};
}
