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

	/// <summary>
	/// Podsumowanie informacji o RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
		}
		RegisterForm(Form^ prevForm)
		{
			InitializeComponent();
			this->prevForm = prevForm;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ prevForm;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Label^ RegisterLabel;
	private: System::Windows::Forms::Label^ emailLabelRegister;
	private: System::Windows::Forms::Label^ passwordLabelRegister;
	private: System::Windows::Forms::Label^ rPasswordLabelRegister;
	private: System::Windows::Forms::TextBox^ emailTbRegister;
	private: System::Windows::Forms::TextBox^ passwordTbRegister;
	private: System::Windows::Forms::TextBox^ rPasswordTbRegister;
	private: System::Windows::Forms::Button^ registerBtn;

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
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->RegisterLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabelRegister = (gcnew System::Windows::Forms::Label());
			this->passwordLabelRegister = (gcnew System::Windows::Forms::Label());
			this->rPasswordLabelRegister = (gcnew System::Windows::Forms::Label());
			this->emailTbRegister = (gcnew System::Windows::Forms::TextBox());
			this->passwordTbRegister = (gcnew System::Windows::Forms::TextBox());
			this->rPasswordTbRegister = (gcnew System::Windows::Forms::TextBox());
			this->registerBtn = (gcnew System::Windows::Forms::Button());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// RegisterLabel
			// 
			this->RegisterLabel->AutoSize = true;
			this->RegisterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->RegisterLabel->Location = System::Drawing::Point(46, 37);
			this->RegisterLabel->Name = L"RegisterLabel";
			this->RegisterLabel->Size = System::Drawing::Size(236, 39);
			this->RegisterLabel->TabIndex = 0;
			this->RegisterLabel->Text = L"Zarejestruj siê";
			// 
			// emailLabelRegister
			// 
			this->emailLabelRegister->AutoSize = true;
			this->emailLabelRegister->Location = System::Drawing::Point(53, 136);
			this->emailLabelRegister->Name = L"emailLabelRegister";
			this->emailLabelRegister->Size = System::Drawing::Size(35, 13);
			this->emailLabelRegister->TabIndex = 1;
			this->emailLabelRegister->Text = L"Email:";
			// 
			// passwordLabelRegister
			// 
			this->passwordLabelRegister->AutoSize = true;
			this->passwordLabelRegister->Location = System::Drawing::Point(53, 178);
			this->passwordLabelRegister->Name = L"passwordLabelRegister";
			this->passwordLabelRegister->Size = System::Drawing::Size(39, 13);
			this->passwordLabelRegister->TabIndex = 2;
			this->passwordLabelRegister->Text = L"Has³o:";
			// 
			// rPasswordLabelRegister
			// 
			this->rPasswordLabelRegister->AutoSize = true;
			this->rPasswordLabelRegister->Location = System::Drawing::Point(34, 215);
			this->rPasswordLabelRegister->Name = L"rPasswordLabelRegister";
			this->rPasswordLabelRegister->Size = System::Drawing::Size(78, 13);
			this->rPasswordLabelRegister->TabIndex = 3;
			this->rPasswordLabelRegister->Text = L"Powtórz has³o:";
			// 
			// emailTbRegister
			// 
			this->emailTbRegister->Location = System::Drawing::Point(147, 133);
			this->emailTbRegister->Name = L"emailTbRegister";
			this->emailTbRegister->Size = System::Drawing::Size(100, 20);
			this->emailTbRegister->TabIndex = 4;
			this->emailTbRegister->TextChanged += gcnew System::EventHandler(this, &RegisterForm::emailTbRegister_TextChanged);
			// 
			// passwordTbRegister
			// 
			this->passwordTbRegister->Location = System::Drawing::Point(147, 175);
			this->passwordTbRegister->Name = L"passwordTbRegister";
			this->passwordTbRegister->PasswordChar = '*';
			this->passwordTbRegister->Size = System::Drawing::Size(100, 20);
			this->passwordTbRegister->TabIndex = 5;
			this->passwordTbRegister->TextChanged += gcnew System::EventHandler(this, &RegisterForm::passwordTbRegister_TextChanged);
			// 
			// rPasswordTbRegister
			// 
			this->rPasswordTbRegister->Location = System::Drawing::Point(147, 212);
			this->rPasswordTbRegister->Name = L"rPasswordTbRegister";
			this->rPasswordTbRegister->PasswordChar = '*';
			this->rPasswordTbRegister->Size = System::Drawing::Size(100, 20);
			this->rPasswordTbRegister->TabIndex = 6;
			this->rPasswordTbRegister->TextChanged += gcnew System::EventHandler(this, &RegisterForm::rPasswordTbRegister_TextChanged);
			// 
			// registerBtn
			// 
			this->registerBtn->Location = System::Drawing::Point(109, 261);
			this->registerBtn->Name = L"registerBtn";
			this->registerBtn->Size = System::Drawing::Size(75, 23);
			this->registerBtn->TabIndex = 7;
			this->registerBtn->Text = L"Zarejestruj";
			this->registerBtn->UseVisualStyleBackColor = true;
			this->registerBtn->Click += gcnew System::EventHandler(this, &RegisterForm::registerBtn_Click);
			// 
			// goBackBtn
			// 
			this->goBackBtn->Location = System::Drawing::Point(9, 8);
			this->goBackBtn->Margin = System::Windows::Forms::Padding(2);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(71, 27);
			this->goBackBtn->TabIndex = 9;
			this->goBackBtn->Text = L"<- powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &RegisterForm::goBackBtn_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 310);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->registerBtn);
			this->Controls->Add(this->rPasswordTbRegister);
			this->Controls->Add(this->passwordTbRegister);
			this->Controls->Add(this->emailTbRegister);
			this->Controls->Add(this->rPasswordLabelRegister);
			this->Controls->Add(this->passwordLabelRegister);
			this->Controls->Add(this->emailLabelRegister);
			this->Controls->Add(this->RegisterLabel);
			this->Name = L"RegisterForm";
			this->Text = L"Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RegisterForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		//Application::Exit();
	}

	private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->setRegisterBtnAvailability();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	
	private: bool validateEmail(String^ toValidate) {
		try {
			MailAddress^ email = gcnew MailAddress(toValidate);
			return true;
		}
		catch (Exception^ e) { return false; }

	}
	private: void setRegisterBtnAvailability() {
		this->registerBtn->Enabled = false;
		if (validateEmail(this->emailTbRegister->Text) && this->passwordTbRegister->Text->Length > 0 && this->rPasswordTbRegister->Text->Length > 0) {
			this->registerBtn->Enabled = true;
		}
	}

	private: System::Void registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->rPasswordTbRegister->Text == this->passwordTbRegister->Text) {
			String^ login = this->emailTbRegister->Text;
			String^ password = this->passwordTbRegister->Text;
			if (DB::getUserIdByLogin(login) == -1) // nie ma jeszcze konta z tym adresem email, zakladanie 
			{
				int userId = DB::addUser(login, password);
				if (userId != -1) { //konto utworzone opomyslnie
					List<String^>^ userData = DB::getUserData(userId);
					User^ nUser = gcnew User(int::Parse(userData[0]), userData[1], int::Parse(userData[2]));
					this->user = nUser;
					this->Close();
				}
				else {
					MessageBox::Show("B³ad przy rejestracji konta", "Spróbuj ponownie", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			} else { // istnieje juz konto z tym adresem email
				MessageBox::Show("Istnieje ju¿ kotno z tym adresem email", "Podaj inny adres email", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Podane has³a s¹ ró¿ne", "Wpisz to samo has³o", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	public: User^ getUser() {
		return this->user;
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}

	private: System::Void emailTbRegister_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->setRegisterBtnAvailability();
	}

	private: System::Void passwordTbRegister_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->setRegisterBtnAvailability();
	}

	private: System::Void rPasswordTbRegister_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->setRegisterBtnAvailability();
	}
};
}
