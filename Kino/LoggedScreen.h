#pragma once
#include "User.h"
#include "PickDateForm.h"
#include "MyTickets.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o LoggedScreen
	/// </summary>
	public ref class LoggedScreen : public System::Windows::Forms::Form
	{
	public:
		LoggedScreen(void)
		{
			InitializeComponent();
		}
		LoggedScreen(Form^ startScreen, User^ user)
		{
			InitializeComponent();
			this->startScreen = startScreen;
			this->user = user;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~LoggedScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ browseMoviesBtn;
	private: System::Windows::Forms::Button^ myTicketsBtn;
	protected:


	private: System::Windows::Forms::Button^ logOutBtn;

	private: Form^ startScreen;
	private: User^ user = nullptr;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoggedScreen::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->browseMoviesBtn = (gcnew System::Windows::Forms::Button());
			this->myTicketsBtn = (gcnew System::Windows::Forms::Button());
			this->logOutBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(179, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 59);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Witaj";
			// 
			// browseMoviesBtn
			// 
			this->browseMoviesBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->browseMoviesBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->browseMoviesBtn->Location = System::Drawing::Point(134, 152);
			this->browseMoviesBtn->Name = L"browseMoviesBtn";
			this->browseMoviesBtn->Size = System::Drawing::Size(222, 78);
			this->browseMoviesBtn->TabIndex = 1;
			this->browseMoviesBtn->Text = L"Przegl¹daj repertuar";
			this->browseMoviesBtn->UseVisualStyleBackColor = true;
			this->browseMoviesBtn->Click += gcnew System::EventHandler(this, &LoggedScreen::browseMoviesBtn_Click);
			// 
			// myTicketsBtn
			// 
			this->myTicketsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->myTicketsBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold));
			this->myTicketsBtn->Location = System::Drawing::Point(134, 241);
			this->myTicketsBtn->Name = L"myTicketsBtn";
			this->myTicketsBtn->Size = System::Drawing::Size(222, 78);
			this->myTicketsBtn->TabIndex = 2;
			this->myTicketsBtn->Text = L"Moje bilety";
			this->myTicketsBtn->UseVisualStyleBackColor = true;
			this->myTicketsBtn->Click += gcnew System::EventHandler(this, &LoggedScreen::myTicketsBtn_Click);
			// 
			// logOutBtn
			// 
			this->logOutBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logOutBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 18, System::Drawing::FontStyle::Bold));
			this->logOutBtn->Location = System::Drawing::Point(134, 334);
			this->logOutBtn->Name = L"logOutBtn";
			this->logOutBtn->Size = System::Drawing::Size(222, 78);
			this->logOutBtn->TabIndex = 3;
			this->logOutBtn->Text = L"Wyloguj siê";
			this->logOutBtn->UseVisualStyleBackColor = true;
			this->logOutBtn->Click += gcnew System::EventHandler(this, &LoggedScreen::logOutBtn_Click);
			// 
			// LoggedScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 443);
			this->Controls->Add(this->logOutBtn);
			this->Controls->Add(this->myTicketsBtn);
			this->Controls->Add(this->browseMoviesBtn);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LoggedScreen";
			this->Text = L"Panel u¿ytkownika - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoggedScreen::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &LoggedScreen::LoggedScreen_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoggedScreen_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void logOutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->startScreen->Show();
	}

	private: System::Void browseMoviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		PickDateForm^ pickDateForm = gcnew PickDateForm(this, this->user);
		this->Hide();
		pickDateForm->Show();
	}

	private: System::Void myTicketsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MyTickets^ myTickets = gcnew MyTickets(this, this->user);
		this->Hide();
		myTickets->Show();
	}
};
}
