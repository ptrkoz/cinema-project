#pragma once
#include "DB.h"
#include "User.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net::Mail;
	//using namespace System::Data::SqlClient;
	//using namespace System::Data::Odbc;

	/// <summary>
	/// Podsumowanie informacji o LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
		}

		LoginForm(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}

		LoginForm(Form^ prevForm, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->user = user;
		}
	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ prevForm;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Label^ LoginLabel;
	private: System::Windows::Forms::Label^ emailLoginLabel;
	private: System::Windows::Forms::TextBox^ emailLoginTextBox;
	private: System::Windows::Forms::Label^ passwordLoginLabel;
	private: System::Windows::Forms::TextBox^ passwordLoginTextBox;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Button^ goBackBtn;


	protected:


	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LoginLabel = (gcnew System::Windows::Forms::Label());
			this->emailLoginLabel = (gcnew System::Windows::Forms::Label());
			this->emailLoginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLoginLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLoginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LoginLabel
			// 
			this->LoginLabel->AutoSize = true;
			this->LoginLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LoginLabel->Location = System::Drawing::Point(51, 38);
			this->LoginLabel->Name = L"LoginLabel";
			this->LoginLabel->Size = System::Drawing::Size(184, 39);
			this->LoginLabel->TabIndex = 0;
			this->LoginLabel->Text = L"Zaloguj si�";
			// 
			// emailLoginLabel
			// 
			this->emailLoginLabel->AutoSize = true;
			this->emailLoginLabel->Location = System::Drawing::Point(49, 119);
			this->emailLoginLabel->Name = L"emailLoginLabel";
			this->emailLoginLabel->Size = System::Drawing::Size(35, 13);
			this->emailLoginLabel->TabIndex = 1;
			this->emailLoginLabel->Text = L"Email:";
			// 
			// emailLoginTextBox
			// 
			this->emailLoginTextBox->Location = System::Drawing::Point(100, 116);
			this->emailLoginTextBox->Name = L"emailLoginTextBox";
			this->emailLoginTextBox->Size = System::Drawing::Size(100, 20);
			this->emailLoginTextBox->TabIndex = 2;
			this->emailLoginTextBox->TextChanged += gcnew System::EventHandler(this, &LoginForm::emailLoginTextBox_TextChanged);
			// 
			// passwordLoginLabel
			// 
			this->passwordLoginLabel->AutoSize = true;
			this->passwordLoginLabel->Location = System::Drawing::Point(49, 170);
			this->passwordLoginLabel->Name = L"passwordLoginLabel";
			this->passwordLoginLabel->Size = System::Drawing::Size(39, 13);
			this->passwordLoginLabel->TabIndex = 3;
			this->passwordLoginLabel->Text = L"Has�o:";
			// 
			// passwordLoginTextBox
			// 
			this->passwordLoginTextBox->Location = System::Drawing::Point(100, 167);
			this->passwordLoginTextBox->Name = L"passwordLoginTextBox";
			this->passwordLoginTextBox->PasswordChar = '*';
			this->passwordLoginTextBox->Size = System::Drawing::Size(100, 20);
			this->passwordLoginTextBox->TabIndex = 4;
			this->passwordLoginTextBox->TextChanged += gcnew System::EventHandler(this, &LoginForm::passwordLoginTextBox_TextChanged);
			// 
			// loginBtn
			// 
			this->loginBtn->Location = System::Drawing::Point(99, 213);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(75, 23);
			this->loginBtn->TabIndex = 5;
			this->loginBtn->Text = L"Zaloguj";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &LoginForm::loginBtn_Click);
			// 
			// goBackBtn
			// 
			this->goBackBtn->Location = System::Drawing::Point(9, 8);
			this->goBackBtn->Margin = System::Windows::Forms::Padding(2);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(64, 20);
			this->goBackBtn->TabIndex = 6;
			this->goBackBtn->Text = L"<- powr�t";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &LoginForm::goBackBtn_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->passwordLoginTextBox);
			this->Controls->Add(this->passwordLoginLabel);
			this->Controls->Add(this->emailLoginTextBox);
			this->Controls->Add(this->emailLoginLabel);
			this->Controls->Add(this->LoginLabel);
			this->Name = L"LoginForm";
			this->Text = L"Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//private: static User^ user = nullptr;

	/*public: static User^ getUser() {
		return LoginForm::user;
	}*/

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	//	Application::Exit();
	}

	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->setLoginBtnAvailability();
	}
	
	private: bool validateEmail(String^ toValidate) {
		try {
			MailAddress^ email = gcnew MailAddress(toValidate);
			return true;
		} catch (Exception^ e) { return false; }
	}

	private: void setLoginBtnAvailability() {
		this->loginBtn->Enabled = false;
		if (validateEmail(this->emailLoginTextBox->Text) && this->passwordLoginTextBox->Text->Length > 0) {
			this->loginBtn->Enabled = true;
		}
	}

	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ login = this->emailLoginTextBox->Text;
		String^ password = this->passwordLoginTextBox->Text;
		try
		{
			int userId = DB::checkUserCredentials(login, password);
			if (userId != -1) { // uzytkownik wprowadzil poprawne dane logowania
				List<String^>^ userData = DB::getUserData(userId);
				User^ nUser = gcnew User(int::Parse(userData[0]), userData[1], int::Parse(userData[2]));
				this->user = nUser;
				this->Close();
			}
			else {
				MessageBox::Show("B��dny login lub has�o", "Nie zalogowano", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
	
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->ToString());
		}
	}

	public: User^ getUser() {
		return this->user;
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void emailLoginTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->setLoginBtnAvailability();
	}

	private: System::Void passwordLoginTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->setLoginBtnAvailability();
	}
};
}
