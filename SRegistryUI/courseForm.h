#pragma once
#include<string>
#include"registry.h"

namespace SRegistryUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for courseForm
	/// </summary>
	public ref class courseForm : public System::Windows::Forms::Form
	{
	public:
		courseForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		courseForm(registry* reg)
		{
			InitializeComponent();
			reg->refreshCourse(listBoxCourse);
		}
		String^ course;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~courseForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::ListBox^  listBoxCourse;

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
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->listBoxCourse = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelName->Location = System::Drawing::Point(206, 27);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(207, 42);
			this->labelName->TabIndex = 0;
			this->labelName->Text = L"Course List";
			// 
			// listBoxCourse
			// 
			this->listBoxCourse->FormattingEnabled = true;
			this->listBoxCourse->Location = System::Drawing::Point(37, 104);
			this->listBoxCourse->Name = L"listBoxCourse";
			this->listBoxCourse->Size = System::Drawing::Size(577, 485);
			this->listBoxCourse->TabIndex = 1;
			this->listBoxCourse->SelectedIndexChanged += gcnew System::EventHandler(this, &courseForm::listBox1_SelectedIndexChanged);
			// 
			// courseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 621);
			this->Controls->Add(this->listBoxCourse);
			this->Controls->Add(this->labelName);
			this->Name = L"courseForm";
			this->Text = L"courseForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
