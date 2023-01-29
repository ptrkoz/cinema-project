#pragma once
#include "DB.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EditRoom
	/// </summary>
	public ref class EditRoom : public System::Windows::Forms::Form
	{
	public:
		EditRoom(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}
		EditRoom(int roomId)
		{
			InitializeComponent();
			this->roomId = roomId;
		}
	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~EditRoom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int roomId = -1;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ saveChangesBtn;
	private: System::Windows::Forms::Button^ goBackBtn;


	private: System::Windows::Forms::Button^ addRoomBtn;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveChangesBtn = (gcnew System::Windows::Forms::Button());
			this->goBackBtn = (gcnew System::Windows::Forms::Button());
			this->addRoomBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nazwa sali:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(151, 42);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 31);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &EditRoom::textBox1_TextChanged);
			// 
			// saveChangesBtn
			// 
			this->saveChangesBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->saveChangesBtn->Location = System::Drawing::Point(50, 107);
			this->saveChangesBtn->Name = L"saveChangesBtn";
			this->saveChangesBtn->Size = System::Drawing::Size(118, 49);
			this->saveChangesBtn->TabIndex = 2;
			this->saveChangesBtn->Text = L"Zapisz zmiany";
			this->saveChangesBtn->UseVisualStyleBackColor = true;
			this->saveChangesBtn->Click += gcnew System::EventHandler(this, &EditRoom::saveChangesBtn_Click);
			// 
			// goBackBtn
			// 
			this->goBackBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->goBackBtn->Location = System::Drawing::Point(174, 107);
			this->goBackBtn->Name = L"goBackBtn";
			this->goBackBtn->Size = System::Drawing::Size(109, 49);
			this->goBackBtn->TabIndex = 3;
			this->goBackBtn->Text = L"Anuluj";
			this->goBackBtn->UseVisualStyleBackColor = true;
			this->goBackBtn->Click += gcnew System::EventHandler(this, &EditRoom::goBackBtn_Click);
			// 
			// addRoomBtn
			// 
			this->addRoomBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->addRoomBtn->Location = System::Drawing::Point(50, 107);
			this->addRoomBtn->Name = L"addRoomBtn";
			this->addRoomBtn->Size = System::Drawing::Size(118, 49);
			this->addRoomBtn->TabIndex = 4;
			this->addRoomBtn->Text = L"Dodaj sale";
			this->addRoomBtn->UseVisualStyleBackColor = true;
			this->addRoomBtn->Click += gcnew System::EventHandler(this, &EditRoom::addRoomBtn_Click);
			// 
			// EditRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(347, 168);
			this->Controls->Add(this->addRoomBtn);
			this->Controls->Add(this->goBackBtn);
			this->Controls->Add(this->saveChangesBtn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"EditRoom";
			this->Text = L"EditRoom";
			this->Load += gcnew System::EventHandler(this, &EditRoom::EditRoom_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EditRoom_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->setSaveBtnsVisibility();
		if (this->roomId != -1) {
			this->setRoomName();
		}
		this->setBtnsAvailability();
	}

	private: void setSaveBtnsVisibility() {
		if (this->roomId == -1) { // przy dodawaniu nowej sali
			this->saveChangesBtn->Visible = false;
			this->addRoomBtn->Visible = true;
		}
		else { // przy edycji istniej¹cej sali
			this->addRoomBtn->Visible = false;
			this->saveChangesBtn->Visible = true;
		}
	}

	private: void setBtnsAvailability() {
		if (this->textBox1->Text->Length > 0) {
			this->saveChangesBtn->Enabled = true;
			this->addRoomBtn->Enabled = true;
		}
		else {
			this->saveChangesBtn->Enabled = false;
			this->addRoomBtn->Enabled = false;
		}
	}

	private: System::Void goBackBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: void setRoomName() {
		String^ roomName = DB::getRoomName(this->roomId);
		this->textBox1->Text = roomName;
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->setBtnsAvailability();
	}

	private: System::Void addRoomBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ roomName = this->textBox1->Text;
		DB::addRoom(roomName);
		this->Close();
	}
	private: System::Void saveChangesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ roomName = this->textBox1->Text;
		DB::editRoom(this->roomId, roomName);
		this->Close();
	}
};
}
