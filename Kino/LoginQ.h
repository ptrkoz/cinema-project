#pragma once

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o LoginQ
	/// </summary>
	public ref class LoginQ : public System::Windows::Forms::Form
	{
	public:
		LoginQ(void)
		{
			InitializeComponent();
		}
		int choice = 0;
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~LoginQ()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Button^ registerBtn;


	private: System::Windows::Forms::Button^ guestBtn;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->registerBtn = (gcnew System::Windows::Forms::Button());
			this->guestBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(102, 36);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Czy chesz sie zalogowaæ\?";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// loginBtn
			// 
			this->loginBtn->Location = System::Drawing::Point(16, 78);
			this->loginBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(66, 25);
			this->loginBtn->TabIndex = 2;
			this->loginBtn->Text = L"Zaloguj siê";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &LoginQ::loginBtn_Click);
			// 
			// registerBtn
			// 
			this->registerBtn->Location = System::Drawing::Point(105, 78);
			this->registerBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->registerBtn->Name = L"registerBtn";
			this->registerBtn->Size = System::Drawing::Size(85, 25);
			this->registerBtn->TabIndex = 3;
			this->registerBtn->Text = L"Zarejestruj siê";
			this->registerBtn->UseVisualStyleBackColor = true;
			this->registerBtn->Click += gcnew System::EventHandler(this, &LoginQ::registerBtn_Click);
			// 
			// guestBtn
			// 
			this->guestBtn->Location = System::Drawing::Point(209, 78);
			this->guestBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->guestBtn->Name = L"guestBtn";
			this->guestBtn->Size = System::Drawing::Size(110, 25);
			this->guestBtn->TabIndex = 4;
			this->guestBtn->Text = L"Kontynuj bez konta";
			this->guestBtn->UseVisualStyleBackColor = true;
			this->guestBtn->Click += gcnew System::EventHandler(this, &LoginQ::guestBtn_Click);
			// 
			// LoginQ
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 111);
			this->Controls->Add(this->guestBtn);
			this->Controls->Add(this->registerBtn);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"LoginQ";
			this->Text = L"LoginQ";
			this->Load += gcnew System::EventHandler(this, &LoginQ::LoginQ_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void LoginQ_Load(System::Object^ sender, System::EventArgs^ e) {
			this->CenterToScreen();
	}

	private: System::Void guestBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->choice = 1;
		this->Close();
	}

	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->choice = 2;
		this->Close();
	}
	
	private: System::Void registerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->choice = 3;
		this->Close();
	}


};
}
