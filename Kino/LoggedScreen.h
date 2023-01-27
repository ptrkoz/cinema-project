#pragma once
#include "User.h"
#include "PickDateForm.h"

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
	protected:

	private: System::Windows::Forms::Button^ button2;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->browseMoviesBtn = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->logOutBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(87, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Witaj";
			// 
			// browseMoviesBtn
			// 
			this->browseMoviesBtn->Location = System::Drawing::Point(79, 130);
			this->browseMoviesBtn->Name = L"browseMoviesBtn";
			this->browseMoviesBtn->Size = System::Drawing::Size(117, 23);
			this->browseMoviesBtn->TabIndex = 1;
			this->browseMoviesBtn->Text = L"Przegl¹daj repertuar";
			this->browseMoviesBtn->UseVisualStyleBackColor = true;
			this->browseMoviesBtn->Click += gcnew System::EventHandler(this, &LoggedScreen::browseMoviesBtn_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(98, 168);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Moje bilety";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// logOutBtn
			// 
			this->logOutBtn->Location = System::Drawing::Point(98, 210);
			this->logOutBtn->Name = L"logOutBtn";
			this->logOutBtn->Size = System::Drawing::Size(75, 23);
			this->logOutBtn->TabIndex = 3;
			this->logOutBtn->Text = L"Wyloguj siê";
			this->logOutBtn->UseVisualStyleBackColor = true;
			this->logOutBtn->Click += gcnew System::EventHandler(this, &LoggedScreen::logOutBtn_Click);
			// 
			// LoggedScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->logOutBtn);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->browseMoviesBtn);
			this->Controls->Add(this->label1);
			this->Name = L"LoggedScreen";
			this->Text = L"LoggedScreen";
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
};
}
