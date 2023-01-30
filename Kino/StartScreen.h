#pragma once
#include "DB.h"
//#include "User.h"
#include "LoginForm.h"
#include "LoggedScreen.h"
#include "AdminScreen.h"
#include "RegisterForm.h"
#include "PickDateForm.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;

	public ref class StartScreen : public System::Windows::Forms::Form
	{
	public:
		StartScreen(void)
		{
			InitializeComponent();
			DB::connect();
		}

	protected:
		~StartScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ browseMoviesBtn;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Button^ registerBtn;
	private: System::Windows::Forms::Button^ aboutBtn;
	private: System::Windows::Forms::Button^ exitBtn;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartScreen::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->browseMoviesBtn = (gcnew System::Windows::Forms::Button());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->registerBtn = (gcnew System::Windows::Forms::Button());
			this->aboutBtn = (gcnew System::Windows::Forms::Button());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(216, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 78);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Kino";
			this->label1->Click += gcnew System::EventHandler(this, &StartScreen::label1_Click);
			// 
			// browseMoviesBtn
			// 
			this->browseMoviesBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->browseMoviesBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->browseMoviesBtn->Location = System::Drawing::Point(177, 151);
			this->browseMoviesBtn->Name = L"browseMoviesBtn";
			this->browseMoviesBtn->Size = System::Drawing::Size(235, 68);
			this->browseMoviesBtn->TabIndex = 1;
			this->browseMoviesBtn->Text = L"Przegl¹daj repertuar";
			this->browseMoviesBtn->UseVisualStyleBackColor = true;
			this->browseMoviesBtn->Click += gcnew System::EventHandler(this, &StartScreen::browseMoviesBtn_Click);
			// 
			// loginBtn
			// 
			this->loginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold));
			this->loginBtn->Location = System::Drawing::Point(42, 247);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(235, 68);
			this->loginBtn->TabIndex = 2;
			this->loginBtn->Text = L"Zaloguj siê";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &StartScreen::loginBtn_Click);
			// 
			// registerBtn
			// 
			this->registerBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->registerBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold));
			this->registerBtn->Location = System::Drawing::Point(298, 247);
			this->registerBtn->Name = L"registerBtn";
			this->registerBtn->Size = System::Drawing::Size(235, 68);
			this->registerBtn->TabIndex = 3;
			this->registerBtn->Text = L"Zarejestruj siê";
			this->registerBtn->UseVisualStyleBackColor = true;
			this->registerBtn->Click += gcnew System::EventHandler(this, &StartScreen::registerBtn_Click);
			// 
			// aboutBtn
			// 
			this->aboutBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->aboutBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold));
			this->aboutBtn->Location = System::Drawing::Point(42, 351);
			this->aboutBtn->Name = L"aboutBtn";
			this->aboutBtn->Size = System::Drawing::Size(235, 68);
			this->aboutBtn->TabIndex = 4;
			this->aboutBtn->Text = L"O aplikacji";
			this->aboutBtn->UseVisualStyleBackColor = true;
			this->aboutBtn->Click += gcnew System::EventHandler(this, &StartScreen::aboutBtn_Click);
			// 
			// exitBtn
			// 
			this->exitBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold));
			this->exitBtn->Location = System::Drawing::Point(298, 351);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(235, 68);
			this->exitBtn->TabIndex = 5;
			this->exitBtn->Text = L"WyjdŸ";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &StartScreen::exitBtn_Click);
			// 
			// StartScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 478);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->aboutBtn);
			this->Controls->Add(this->registerBtn);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->browseMoviesBtn);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StartScreen";
			this->Text = L"Ekran g³ówny - Kino";
			this->Load += gcnew System::EventHandler(this, &StartScreen::StartScreen_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void browseMoviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		PickDateForm^ pickDateForm = gcnew PickDateForm(this);
		this->Hide();
		pickDateForm->Show();
	}

	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginForm^ loginForm = gcnew LoginForm(this);
		this->Hide();
		loginForm->ShowDialog();
		if (loginForm->getUser() != nullptr) {
			if (loginForm->getUser()->getPermissions() == 1) {
				AdminScreen^ adminScreen = gcnew AdminScreen(this, loginForm->getUser());
				adminScreen->Show();
			} else {
				LoggedScreen^ loggedScreen = gcnew LoggedScreen(this, loginForm->getUser());
				loggedScreen->Show();
			}
		} else {
			this->Show();
		}
	}

	private: System::Void registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForm^ registerForm = gcnew RegisterForm(this);
		this->Hide();
		registerForm->ShowDialog();
		if (registerForm->getUser() != nullptr) {
			LoggedScreen^ loggedScreen = gcnew LoggedScreen(this, registerForm->getUser());
			loggedScreen->Show();
		}
		else {
			this->Show();
		}
	}

	private: System::Void StartScreen_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
	}

	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void aboutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Aplikacja dla klientów kina oraz do zarz¹dzania kinem.\n\nAutor: Piotr Kozera", "O aplikacji", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}
