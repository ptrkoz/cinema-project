#pragma once
#include "User.h"
#include "AdminMovies.h"
#include "AdminShows.h"
#include "AdminRooms.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o AdminScreen
	/// </summary>
	public ref class AdminScreen : public System::Windows::Forms::Form
	{
	public:
		AdminScreen(void)
		{
			InitializeComponent();
		}
		AdminScreen(Form^ prevForm, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->user = user;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~AdminScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ prevForm;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ MovieBtn;
	private: System::Windows::Forms::Button^ ShowBtn;
	private: System::Windows::Forms::Button^ RoomsBtn;
	private: System::Windows::Forms::Button^ logOutBtn;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminScreen::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MovieBtn = (gcnew System::Windows::Forms::Button());
			this->ShowBtn = (gcnew System::Windows::Forms::Button());
			this->RoomsBtn = (gcnew System::Windows::Forms::Button());
			this->logOutBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(88, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(335, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Panel administratora";
			// 
			// MovieBtn
			// 
			this->MovieBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MovieBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->MovieBtn->Location = System::Drawing::Point(138, 153);
			this->MovieBtn->Name = L"MovieBtn";
			this->MovieBtn->Size = System::Drawing::Size(221, 73);
			this->MovieBtn->TabIndex = 1;
			this->MovieBtn->Text = L"Filmy";
			this->MovieBtn->UseVisualStyleBackColor = true;
			this->MovieBtn->Click += gcnew System::EventHandler(this, &AdminScreen::MovieBtn_Click);
			// 
			// ShowBtn
			// 
			this->ShowBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ShowBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ShowBtn->Location = System::Drawing::Point(138, 246);
			this->ShowBtn->Name = L"ShowBtn";
			this->ShowBtn->Size = System::Drawing::Size(221, 73);
			this->ShowBtn->TabIndex = 2;
			this->ShowBtn->Text = L"Seanse";
			this->ShowBtn->UseVisualStyleBackColor = true;
			this->ShowBtn->Click += gcnew System::EventHandler(this, &AdminScreen::ShowBtnClick);
			// 
			// RoomsBtn
			// 
			this->RoomsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RoomsBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->RoomsBtn->Location = System::Drawing::Point(138, 341);
			this->RoomsBtn->Name = L"RoomsBtn";
			this->RoomsBtn->Size = System::Drawing::Size(221, 73);
			this->RoomsBtn->TabIndex = 3;
			this->RoomsBtn->Text = L"Sale";
			this->RoomsBtn->UseVisualStyleBackColor = true;
			this->RoomsBtn->Click += gcnew System::EventHandler(this, &AdminScreen::RoomsBtn_Click);
			// 
			// logOutBtn
			// 
			this->logOutBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logOutBtn->Font = (gcnew System::Drawing::Font(L"Corbel", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->logOutBtn->Location = System::Drawing::Point(138, 437);
			this->logOutBtn->Name = L"logOutBtn";
			this->logOutBtn->Size = System::Drawing::Size(221, 73);
			this->logOutBtn->TabIndex = 4;
			this->logOutBtn->Text = L"Wyloguj siê";
			this->logOutBtn->UseVisualStyleBackColor = true;
			this->logOutBtn->Click += gcnew System::EventHandler(this, &AdminScreen::logOutBtn_Click);
			// 
			// AdminScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 571);
			this->Controls->Add(this->logOutBtn);
			this->Controls->Add(this->RoomsBtn);
			this->Controls->Add(this->ShowBtn);
			this->Controls->Add(this->MovieBtn);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AdminScreen";
			this->Text = L"Panel administratora - Kino";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AdminScreen::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &AdminScreen::AdminScreen_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AdminScreen_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
	}

	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}

	private: System::Void MovieBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AdminMovies^ adminMovies = gcnew AdminMovies(this);
		this->Hide();
		adminMovies->Show();
	}

	private: System::Void ShowBtnClick(System::Object^ sender, System::EventArgs^ e) {
		AdminShows^ adminShows = gcnew AdminShows(this);
		this->Hide();
		adminShows->Show();
	}

	private: System::Void RoomsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AdminRooms^ adminRooms = gcnew AdminRooms(this);
		this->Hide();
		adminRooms->Show();
	}

	private: System::Void logOutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Restart();
	}
};
}
