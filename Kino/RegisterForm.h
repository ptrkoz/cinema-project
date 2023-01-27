#pragma once

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Label^ RegisterLabel;
	private: System::Windows::Forms::Label^ emailLabelRegister;
	private: System::Windows::Forms::Label^ passwordLabelRegister;
	private: System::Windows::Forms::Label^ rPasswordLabelRegister;
	private: System::Windows::Forms::TextBox^ emailTbRegister;
	private: System::Windows::Forms::TextBox^ passwordTbRegister;
	private: System::Windows::Forms::TextBox^ rPasswordTbRegister;
	private: System::Windows::Forms::Button^ registerBtn;
	private: System::Windows::Forms::Button^ cancelRegisterBtn;
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
			this->cancelRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// RegisterLabel
			// 
			this->RegisterLabel->AutoSize = true;
			this->RegisterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->RegisterLabel->Location = System::Drawing::Point(69, 57);
			this->RegisterLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->RegisterLabel->Name = L"RegisterLabel";
			this->RegisterLabel->Size = System::Drawing::Size(362, 61);
			this->RegisterLabel->TabIndex = 0;
			this->RegisterLabel->Text = L"Zarejestruj siê";
			// 
			// emailLabelRegister
			// 
			this->emailLabelRegister->AutoSize = true;
			this->emailLabelRegister->Location = System::Drawing::Point(80, 209);
			this->emailLabelRegister->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->emailLabelRegister->Name = L"emailLabelRegister";
			this->emailLabelRegister->Size = System::Drawing::Size(52, 20);
			this->emailLabelRegister->TabIndex = 1;
			this->emailLabelRegister->Text = L"Email:";
			// 
			// passwordLabelRegister
			// 
			this->passwordLabelRegister->AutoSize = true;
			this->passwordLabelRegister->Location = System::Drawing::Point(80, 274);
			this->passwordLabelRegister->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->passwordLabelRegister->Name = L"passwordLabelRegister";
			this->passwordLabelRegister->Size = System::Drawing::Size(55, 20);
			this->passwordLabelRegister->TabIndex = 2;
			this->passwordLabelRegister->Text = L"Has³o:";
			// 
			// rPasswordLabelRegister
			// 
			this->rPasswordLabelRegister->AutoSize = true;
			this->rPasswordLabelRegister->Location = System::Drawing::Point(51, 331);
			this->rPasswordLabelRegister->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rPasswordLabelRegister->Name = L"rPasswordLabelRegister";
			this->rPasswordLabelRegister->Size = System::Drawing::Size(113, 20);
			this->rPasswordLabelRegister->TabIndex = 3;
			this->rPasswordLabelRegister->Text = L"Powtórz has³o:";
			// 
			// emailTbRegister
			// 
			this->emailTbRegister->Location = System::Drawing::Point(220, 205);
			this->emailTbRegister->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->emailTbRegister->Name = L"emailTbRegister";
			this->emailTbRegister->Size = System::Drawing::Size(148, 26);
			this->emailTbRegister->TabIndex = 4;
			// 
			// passwordTbRegister
			// 
			this->passwordTbRegister->Location = System::Drawing::Point(220, 269);
			this->passwordTbRegister->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->passwordTbRegister->Name = L"passwordTbRegister";
			this->passwordTbRegister->PasswordChar = '*';
			this->passwordTbRegister->Size = System::Drawing::Size(148, 26);
			this->passwordTbRegister->TabIndex = 5;
			// 
			// rPasswordTbRegister
			// 
			this->rPasswordTbRegister->Location = System::Drawing::Point(220, 326);
			this->rPasswordTbRegister->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->rPasswordTbRegister->Name = L"rPasswordTbRegister";
			this->rPasswordTbRegister->PasswordChar = '*';
			this->rPasswordTbRegister->Size = System::Drawing::Size(148, 26);
			this->rPasswordTbRegister->TabIndex = 6;
			// 
			// registerBtn
			// 
			this->registerBtn->Location = System::Drawing::Point(220, 400);
			this->registerBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->registerBtn->Name = L"registerBtn";
			this->registerBtn->Size = System::Drawing::Size(112, 35);
			this->registerBtn->TabIndex = 7;
			this->registerBtn->Text = L"Zarejestruj";
			this->registerBtn->UseVisualStyleBackColor = true;
			this->registerBtn->Click += gcnew System::EventHandler(this, &RegisterForm::registerBtn_Click);
			// 
			// cancelRegisterBtn
			// 
			this->cancelRegisterBtn->Location = System::Drawing::Point(99, 400);
			this->cancelRegisterBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cancelRegisterBtn->Name = L"cancelRegisterBtn";
			this->cancelRegisterBtn->Size = System::Drawing::Size(112, 35);
			this->cancelRegisterBtn->TabIndex = 8;
			this->cancelRegisterBtn->Text = L"Anuluj";
			this->cancelRegisterBtn->UseVisualStyleBackColor = true;
			this->cancelRegisterBtn->Click += gcnew System::EventHandler(this, &RegisterForm::button2_Click);
			// 
			// goBackBtn
			// 
			this->goBackBtn->Location = System::Drawing::Point(13, 13);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(106, 41);
			this->goBackBtn->TabIndex = 9;
			this->goBackBtn->Text = L"<- powrót";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &RegisterForm::goBackBtn_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(489, 477);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->cancelRegisterBtn);
			this->Controls->Add(this->registerBtn);
			this->Controls->Add(this->rPasswordTbRegister);
			this->Controls->Add(this->passwordTbRegister);
			this->Controls->Add(this->emailTbRegister);
			this->Controls->Add(this->rPasswordLabelRegister);
			this->Controls->Add(this->passwordLabelRegister);
			this->Controls->Add(this->emailLabelRegister);
			this->Controls->Add(this->RegisterLabel);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"RegisterForm";
			this->Text = L"Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RegisterForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	
	private: System::Void registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->RegisterLabel->Text = this->rPasswordTbRegister->Text;
	}
	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->prevForm->Show();
	}
};
}
