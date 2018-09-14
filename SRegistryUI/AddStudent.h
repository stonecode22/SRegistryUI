#pragma once

namespace SRegistryUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for AddStudent
	/// </summary>
	public ref class AddStudent : public System::Windows::Forms::Form
	{
	public:
		AddStudent(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		bool complete()
		{
			if (first->Length == 0 || last->Length == 0 || date->Length == 0 /*|| phone->Length != 11 || zip > 9999 */|| state->Length == 0 || city->Length == 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		String^ first = "";
		String^ last = "";
		String^ date = "";
		String^ phone = "";
		int zip = 0;
		String^ state = "";
		String^ city = "";
		bool honors;
		bool TA;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  AddStudent1;
	private: System::Windows::Forms::Label^  enterFirst;
	private: System::Windows::Forms::Label^  EnterLast;
	private: System::Windows::Forms::Label^  enterDate;
	private: System::Windows::Forms::Label^  enterPhone;
	private: System::Windows::Forms::Label^  enterState;
	private: System::Windows::Forms::TextBox^  boxFirst;
	private: System::Windows::Forms::TextBox^  boxLast;
	private: System::Windows::Forms::TextBox^  boxPhone;
	private: System::Windows::Forms::TextBox^  boxState;
	protected:









	private: System::Windows::Forms::Label^  enterCity;
	private: System::Windows::Forms::Label^  enterZip;
	private: System::Windows::Forms::TextBox^  boxCity;
	private: System::Windows::Forms::TextBox^  boxZip;




	private: System::Windows::Forms::DateTimePicker^  boxDate;



	private: System::Windows::Forms::CheckBox^  checkHonors;
	private: System::Windows::Forms::CheckBox^  checkTA;
	private: System::Windows::Forms::Button^  saveStudent;





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
			this->AddStudent1 = (gcnew System::Windows::Forms::Label());
			this->enterFirst = (gcnew System::Windows::Forms::Label());
			this->EnterLast = (gcnew System::Windows::Forms::Label());
			this->enterDate = (gcnew System::Windows::Forms::Label());
			this->enterPhone = (gcnew System::Windows::Forms::Label());
			this->enterState = (gcnew System::Windows::Forms::Label());
			this->boxFirst = (gcnew System::Windows::Forms::TextBox());
			this->boxLast = (gcnew System::Windows::Forms::TextBox());
			this->boxPhone = (gcnew System::Windows::Forms::TextBox());
			this->boxState = (gcnew System::Windows::Forms::TextBox());
			this->enterCity = (gcnew System::Windows::Forms::Label());
			this->enterZip = (gcnew System::Windows::Forms::Label());
			this->boxCity = (gcnew System::Windows::Forms::TextBox());
			this->boxZip = (gcnew System::Windows::Forms::TextBox());
			this->boxDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->checkHonors = (gcnew System::Windows::Forms::CheckBox());
			this->checkTA = (gcnew System::Windows::Forms::CheckBox());
			this->saveStudent = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// AddStudent1
			// 
			this->AddStudent1->AutoSize = true;
			this->AddStudent1->Location = System::Drawing::Point(153, 26);
			this->AddStudent1->Name = L"AddStudent1";
			this->AddStudent1->Size = System::Drawing::Size(66, 13);
			this->AddStudent1->TabIndex = 0;
			this->AddStudent1->Text = L"Add Student";
			// 
			// enterFirst
			// 
			this->enterFirst->AutoSize = true;
			this->enterFirst->Location = System::Drawing::Point(32, 86);
			this->enterFirst->Name = L"enterFirst";
			this->enterFirst->Size = System::Drawing::Size(63, 13);
			this->enterFirst->TabIndex = 1;
			this->enterFirst->Text = L"First Name: ";
			this->enterFirst->Click += gcnew System::EventHandler(this, &AddStudent::enterName_Click);
			// 
			// EnterLast
			// 
			this->EnterLast->AutoSize = true;
			this->EnterLast->Location = System::Drawing::Point(32, 120);
			this->EnterLast->Name = L"EnterLast";
			this->EnterLast->Size = System::Drawing::Size(64, 13);
			this->EnterLast->TabIndex = 2;
			this->EnterLast->Text = L"Last Name: ";
			this->EnterLast->Click += gcnew System::EventHandler(this, &AddStudent::label1_Click);
			// 
			// enterDate
			// 
			this->enterDate->AutoSize = true;
			this->enterDate->Location = System::Drawing::Point(32, 155);
			this->enterDate->Name = L"enterDate";
			this->enterDate->Size = System::Drawing::Size(101, 13);
			this->enterDate->TabIndex = 3;
			this->enterDate->Text = L"Date of Registration";
			// 
			// enterPhone
			// 
			this->enterPhone->AutoSize = true;
			this->enterPhone->Location = System::Drawing::Point(32, 190);
			this->enterPhone->Name = L"enterPhone";
			this->enterPhone->Size = System::Drawing::Size(81, 13);
			this->enterPhone->TabIndex = 4;
			this->enterPhone->Text = L"Phone Number:";
			// 
			// enterState
			// 
			this->enterState->AutoSize = true;
			this->enterState->Location = System::Drawing::Point(32, 225);
			this->enterState->Name = L"enterState";
			this->enterState->Size = System::Drawing::Size(35, 13);
			this->enterState->TabIndex = 5;
			this->enterState->Text = L"State:";
			// 
			// boxFirst
			// 
			this->boxFirst->Location = System::Drawing::Point(156, 83);
			this->boxFirst->Name = L"boxFirst";
			this->boxFirst->Size = System::Drawing::Size(178, 20);
			this->boxFirst->TabIndex = 6;
			// 
			// boxLast
			// 
			this->boxLast->Location = System::Drawing::Point(156, 117);
			this->boxLast->Name = L"boxLast";
			this->boxLast->Size = System::Drawing::Size(178, 20);
			this->boxLast->TabIndex = 7;
			// 
			// boxPhone
			// 
			this->boxPhone->Location = System::Drawing::Point(156, 187);
			this->boxPhone->Name = L"boxPhone";
			this->boxPhone->Size = System::Drawing::Size(178, 20);
			this->boxPhone->TabIndex = 9;
			// 
			// boxState
			// 
			this->boxState->Location = System::Drawing::Point(156, 222);
			this->boxState->Name = L"boxState";
			this->boxState->Size = System::Drawing::Size(178, 20);
			this->boxState->TabIndex = 10;
			// 
			// enterCity
			// 
			this->enterCity->AutoSize = true;
			this->enterCity->Location = System::Drawing::Point(32, 261);
			this->enterCity->Name = L"enterCity";
			this->enterCity->Size = System::Drawing::Size(27, 13);
			this->enterCity->TabIndex = 11;
			this->enterCity->Text = L"City:";
			// 
			// enterZip
			// 
			this->enterZip->AutoSize = true;
			this->enterZip->Location = System::Drawing::Point(32, 297);
			this->enterZip->Name = L"enterZip";
			this->enterZip->Size = System::Drawing::Size(53, 13);
			this->enterZip->TabIndex = 12;
			this->enterZip->Text = L"Zip Code:";
			// 
			// boxCity
			// 
			this->boxCity->Location = System::Drawing::Point(156, 258);
			this->boxCity->Name = L"boxCity";
			this->boxCity->Size = System::Drawing::Size(178, 20);
			this->boxCity->TabIndex = 13;
			// 
			// boxZip
			// 
			this->boxZip->Location = System::Drawing::Point(156, 294);
			this->boxZip->Name = L"boxZip";
			this->boxZip->Size = System::Drawing::Size(178, 20);
			this->boxZip->TabIndex = 14;
			// 
			// boxDate
			// 
			this->boxDate->Location = System::Drawing::Point(156, 149);
			this->boxDate->Name = L"boxDate";
			this->boxDate->Size = System::Drawing::Size(178, 20);
			this->boxDate->TabIndex = 17;
			this->boxDate->ValueChanged += gcnew System::EventHandler(this, &AddStudent::dateTimePicker1_ValueChanged);
			// 
			// checkHonors
			// 
			this->checkHonors->AutoSize = true;
			this->checkHonors->Location = System::Drawing::Point(35, 341);
			this->checkHonors->Name = L"checkHonors";
			this->checkHonors->Size = System::Drawing::Size(71, 17);
			this->checkHonors->TabIndex = 18;
			this->checkHonors->Text = L"Is Honors";
			this->checkHonors->UseVisualStyleBackColor = true;
			// 
			// checkTA
			// 
			this->checkTA->AutoSize = true;
			this->checkTA->Location = System::Drawing::Point(35, 380);
			this->checkTA->Name = L"checkTA";
			this->checkTA->Size = System::Drawing::Size(51, 17);
			this->checkTA->TabIndex = 19;
			this->checkTA->Text = L"Is TA";
			this->checkTA->UseVisualStyleBackColor = true;
			// 
			// saveStudent
			// 
			this->saveStudent->Location = System::Drawing::Point(135, 463);
			this->saveStudent->Name = L"saveStudent";
			this->saveStudent->Size = System::Drawing::Size(100, 23);
			this->saveStudent->TabIndex = 20;
			this->saveStudent->Text = L"Save";
			this->saveStudent->UseVisualStyleBackColor = true;
			this->saveStudent->Click += gcnew System::EventHandler(this, &AddStudent::saveStudent_Click);
			// 
			// AddStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(378, 509);
			this->Controls->Add(this->saveStudent);
			this->Controls->Add(this->checkTA);
			this->Controls->Add(this->checkHonors);
			this->Controls->Add(this->boxDate);
			this->Controls->Add(this->boxZip);
			this->Controls->Add(this->boxCity);
			this->Controls->Add(this->enterZip);
			this->Controls->Add(this->enterCity);
			this->Controls->Add(this->boxState);
			this->Controls->Add(this->boxPhone);
			this->Controls->Add(this->boxLast);
			this->Controls->Add(this->boxFirst);
			this->Controls->Add(this->enterState);
			this->Controls->Add(this->enterPhone);
			this->Controls->Add(this->enterDate);
			this->Controls->Add(this->EnterLast);
			this->Controls->Add(this->enterFirst);
			this->Controls->Add(this->AddStudent1);
			this->Name = L"AddStudent";
			this->Text = L"AddStudent";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void enterName_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void saveStudent_Click(System::Object^  sender, System::EventArgs^  e) {
	date = boxDate->Value.ToString();
	String^ temp = date->Substring(0, date->IndexOf(" "));
	date = temp;
	first = boxFirst->Text;
	last = boxLast->Text;
	phone = boxPhone->Text;
	zip = Int32::Parse(boxZip->Text);
	state = boxState->Text;
	city = boxCity->Text;
	honors = checkHonors->Checked;
	TA = checkTA->Checked;
	this->Close();

}

};
}
