#pragma once

namespace notepad {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for form
	/// </summary>
	public ref class form : public System::Windows::Forms::Form
	{
	public:
		form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ mbox1;
	private: System::Windows::Forms::Button^ Sbutton;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Button^ Exitbutton;
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
			this->mbox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Sbutton = (gcnew System::Windows::Forms::Button());
			this->label = (gcnew System::Windows::Forms::Label());
			this->Exitbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// mbox1
			// 
			this->mbox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mbox1->BackColor = System::Drawing::SystemColors::Highlight;
			this->mbox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mbox1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->mbox1->Location = System::Drawing::Point(12, 46);
			this->mbox1->Name = L"mbox1";
			this->mbox1->Size = System::Drawing::Size(551, 558);
			this->mbox1->TabIndex = 1;
			this->mbox1->Text = L"";
			this->mbox1->TextChanged += gcnew System::EventHandler(this, &form::mbox1_TextChanged);
			// 
			// Sbutton
			// 
			this->Sbutton->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Sbutton->Location = System::Drawing::Point(12, 17);
			this->Sbutton->Name = L"Sbutton";
			this->Sbutton->Size = System::Drawing::Size(92, 23);
			this->Sbutton->TabIndex = 2;
			this->Sbutton->Text = L"Save";
			this->Sbutton->UseVisualStyleBackColor = false;
			this->Sbutton->Click += gcnew System::EventHandler(this, &form::Sbutton_Click);
			// 
			// label
			// 
			this->label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Stencil", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->ForeColor = System::Drawing::Color::Red;
			this->label->Location = System::Drawing::Point(418, 9);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(137, 27);
			this->label->TabIndex = 3;
			this->label->Text = L"Notepad - -";
			// 
			// Exitbutton
			// 
			this->Exitbutton->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Exitbutton->Location = System::Drawing::Point(110, 17);
			this->Exitbutton->Name = L"Exitbutton";
			this->Exitbutton->Size = System::Drawing::Size(92, 25);
			this->Exitbutton->TabIndex = 4;
			this->Exitbutton->Text = L"Exit";
			this->Exitbutton->UseVisualStyleBackColor = false;
			this->Exitbutton->Click += gcnew System::EventHandler(this, &form::Exitbutton_Click);
			// 
			// form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(575, 613);
			this->Controls->Add(this->Exitbutton);
			this->Controls->Add(this->label);
			this->Controls->Add(this->Sbutton);
			this->Controls->Add(this->mbox1);
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->MinimumSize = System::Drawing::Size(500, 660);
			this->Name = L"form";
			this->Text = L"NOTEPAD - -";
			this->Load += gcnew System::EventHandler(this, &form::form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void form_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Sbutton_Click(System::Object^ sender, System::EventArgs^ e) {
    // Create a SaveFileDialog to let the user choose a file location
    SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
    saveFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";

    if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Get the selected file name
        System::String^ fileName = saveFileDialog1->FileName;

        // Write the content of the RichTextBox to the selected file
        System::IO::File::WriteAllText(fileName, mbox1->Text);

        // Optionally, you can show a message to confirm that the file was saved
        MessageBox::Show("File saved successfully!", "Save Confirmation", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

	private: System::Void mbox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Exitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();

	}
};
}
