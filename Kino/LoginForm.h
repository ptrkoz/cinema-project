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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
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
			this->LoginLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LoginLabel->Location = System::Drawing::Point(176, 92);
			this->LoginLabel->Name = L"LoginLabel";
			this->LoginLabel->Size = System::Drawing::Size(250, 59);
			this->LoginLabel->TabIndex = 0;
			this->LoginLabel->Text = L"Zaloguj siê";
			// 
			// emailLoginLabel
			// 
			this->emailLoginLabel->AutoSize = true;
			this->emailLoginLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->emailLoginLabel->Location = System::Drawing::Point(128, 216);
			this->emailLoginLabel->Name = L"emailLoginLabel";
			this->emailLoginLabel->Size = System::Drawing::Size(89, 33);
			this->emailLoginLabel->TabIndex = 1;
			this->emailLoginLabel->Text = L"Email:";
			// 
			// emailLoginTextBox
			// 
			this->emailLoginTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->emailLoginTextBox->Location = System::Drawing::Point(241, 216);
			this->emailLoginTextBox->Name = L"emailLoginTextBox";
			this->emailLoginTextBox->Size = System::Drawing::Size(225, 31);
			this->emailLoginTextBox->TabIndex = 2;
			this->emailLoginTextBox->TextChanged += gcnew System::EventHandler(this, &LoginForm::emailLoginTextBox_TextChanged);
			// 
			// passwordLoginLabel
			// 
			this->passwordLoginLabel->AutoSize = true;
			this->passwordLoginLabel->Font = (gcnew System::Drawing::Font(L"Corbel", 20.25F, System::Drawing::FontStyle::Bold));
			this->passwordLoginLabel->Location = System::Drawing::Point(128, 274);
			this->passwordLoginLabel->Name = L"passwordLoginLabel";
			this->passwordLoginLabel->Size = System::Drawing::Size(89, 33);
			this->passwordLoginLabel->TabIndex = 3;
			this->passwordLoginLabel->Text = L"Has³o:";
			// 
			// passwordLoginTextBox
			// 
			this->passwordLoginTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->passwordLoginTextBox->Location = System::Drawing::Point(241, 274);
			this->passwordLoginTextBox->Name = L"passwordLoginTextBox";
			this->passwordLoginTextBox->PasswordChar = '*';
			this->passwordLoginTextBox->Size = System::Drawing::Size(225, 31);
			this->passwordLoginTextBox->TabIndex = 4;
			this->passwordLoginTextBox->TextChanged += gcnew System::EventHandler(this, &LoginForm::passwordLoginTextBox_TextChanged);
			// 
			// loginBtn
			// 
			this->loginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->loginBtn->Location = System::Drawing::Point(200, 352);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(208, 63);
			this->loginBtn->TabIndex = 5;
			this->loginBtn->Text = L"Zaloguj";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &LoginForm::loginBtn_Click);
			// 
			// goBackBtn
			// 
			this->goBackBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->goBackBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goBackBtn.Image")));
			this->goBackBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->goBackBtn->Location = System::Drawing::Point(9, 11);
			this->goBackBtn->Margin = System::Windows::Forms::Padding(2);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(137, 52);
			this->goBackBtn->TabIndex = 6;
			this->goBackBtn->Text = L"   powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &LoginForm::goBackBtn_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 467);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->passwordLoginTextBox);
			this->Controls->Add(this->passwordLoginLabel);
			this->Controls->Add(this->emailLoginTextBox);
			this->Controls->Add(this->emailLoginLabel);
			this->Controls->Add(this->LoginLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LoginForm";
			this->Text = L"Logowanie - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

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
				MessageBox::Show("B³êdny login lub has³o", "Nie zalogowano", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
