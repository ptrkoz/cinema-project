#pragma once
#include "User.h"

namespace Kino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o FinalForm
	/// </summary>
	public ref class FinalForm : public System::Windows::Forms::Form
	{
	public:
		FinalForm(void)
		{
			InitializeComponent();
		}
		FinalForm(Form^ prevForm, String^ imageLocation, String^ movieName, String^ showDate, String^ showVersion, String^ showRoom, String^ selectedSeats, String^ ticketCode, int numberOfTickets, User^ user)
		{
			InitializeComponent();
			this->prevForm = prevForm;
			this->imageLocation = imageLocation;
			this->movieName = movieName;
			this->showDate = showDate;
			this->showVersion = showVersion;
			this->showRoom = showRoom;
			this->selectedSeats = selectedSeats;
			this->ticketCode = ticketCode;
			this->numberOfTickets = numberOfTickets;
			this->user = user;
		}
	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~FinalForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
	private: Form^ prevForm;
	private: String^ imageLocation;
	private: String^ movieName;
	private: String^ showDate;
	private: String^ showVersion;
	private: String^ showRoom;
	private: String^ showId;
	private: String^ selectedSeats;
	private: String^ ticketCode;
	private: int numberOfTickets;
	private: User^ user = nullptr;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ movieNameLabel;
	private: System::Windows::Forms::Label^ showDateLabel;
	private: System::Windows::Forms::Label^ showVersionLabel;
	private: System::Windows::Forms::Label^ showRoomLabel;
	private: System::Windows::Forms::Label^ numberOfTicketsLabel;
	private: System::Windows::Forms::Label^ seatsLabel;
	private: System::Windows::Forms::Label^ ticketPriceLabel;
	private: System::Windows::Forms::Label^ ticketCodeLabel;








		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->movieNameLabel = (gcnew System::Windows::Forms::Label());
			this->showDateLabel = (gcnew System::Windows::Forms::Label());
			this->showVersionLabel = (gcnew System::Windows::Forms::Label());
			this->showRoomLabel = (gcnew System::Windows::Forms::Label());
			this->numberOfTicketsLabel = (gcnew System::Windows::Forms::Label());
			this->seatsLabel = (gcnew System::Windows::Forms::Label());
			this->ticketPriceLabel = (gcnew System::Windows::Forms::Label());
			this->ticketCodeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"<- powr�t";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 221);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// movieNameLabel
			// 
			this->movieNameLabel->AutoSize = true;
			this->movieNameLabel->Location = System::Drawing::Point(170, 53);
			this->movieNameLabel->Name = L"movieNameLabel";
			this->movieNameLabel->Size = System::Drawing::Size(63, 13);
			this->movieNameLabel->TabIndex = 2;
			this->movieNameLabel->Text = L"movieName";
			// 
			// showDateLabel
			// 
			this->showDateLabel->AutoSize = true;
			this->showDateLabel->Location = System::Drawing::Point(170, 80);
			this->showDateLabel->Name = L"showDateLabel";
			this->showDateLabel->Size = System::Drawing::Size(55, 13);
			this->showDateLabel->TabIndex = 3;
			this->showDateLabel->Text = L"showDate";
			// 
			// showVersionLabel
			// 
			this->showVersionLabel->AutoSize = true;
			this->showVersionLabel->Location = System::Drawing::Point(173, 110);
			this->showVersionLabel->Name = L"showVersionLabel";
			this->showVersionLabel->Size = System::Drawing::Size(67, 13);
			this->showVersionLabel->TabIndex = 4;
			this->showVersionLabel->Text = L"showVersion";
			// 
			// showRoomLabel
			// 
			this->showRoomLabel->AutoSize = true;
			this->showRoomLabel->Location = System::Drawing::Point(170, 142);
			this->showRoomLabel->Name = L"showRoomLabel";
			this->showRoomLabel->Size = System::Drawing::Size(60, 13);
			this->showRoomLabel->TabIndex = 5;
			this->showRoomLabel->Text = L"showRoom";
			// 
			// numberOfTicketsLabel
			// 
			this->numberOfTicketsLabel->AutoSize = true;
			this->numberOfTicketsLabel->Location = System::Drawing::Point(170, 169);
			this->numberOfTicketsLabel->Name = L"numberOfTicketsLabel";
			this->numberOfTicketsLabel->Size = System::Drawing::Size(88, 13);
			this->numberOfTicketsLabel->TabIndex = 6;
			this->numberOfTicketsLabel->Text = L"numberOfTickets";
			// 
			// seatsLabel
			// 
			this->seatsLabel->AutoSize = true;
			this->seatsLabel->Location = System::Drawing::Point(170, 196);
			this->seatsLabel->Name = L"seatsLabel";
			this->seatsLabel->Size = System::Drawing::Size(58, 13);
			this->seatsLabel->TabIndex = 7;
			this->seatsLabel->Text = L"seatsLabel";
			// 
			// ticketPriceLabel
			// 
			this->ticketPriceLabel->AutoSize = true;
			this->ticketPriceLabel->Location = System::Drawing::Point(173, 229);
			this->ticketPriceLabel->Name = L"ticketPriceLabel";
			this->ticketPriceLabel->Size = System::Drawing::Size(57, 13);
			this->ticketPriceLabel->TabIndex = 8;
			this->ticketPriceLabel->Text = L"ticketPrice";
			// 
			// ticketCodeLabel
			// 
			this->ticketCodeLabel->AutoSize = true;
			this->ticketCodeLabel->Location = System::Drawing::Point(170, 261);
			this->ticketCodeLabel->Name = L"ticketCodeLabel";
			this->ticketCodeLabel->Size = System::Drawing::Size(58, 13);
			this->ticketCodeLabel->TabIndex = 9;
			this->ticketCodeLabel->Text = L"ticketCode";
			// 
			// FinalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 483);
			this->Controls->Add(this->ticketCodeLabel);
			this->Controls->Add(this->ticketPriceLabel);
			this->Controls->Add(this->seatsLabel);
			this->Controls->Add(this->numberOfTicketsLabel);
			this->Controls->Add(this->showRoomLabel);
			this->Controls->Add(this->showVersionLabel);
			this->Controls->Add(this->showDateLabel);
			this->Controls->Add(this->movieNameLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"FinalForm";
			this->Text = L"FinalForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FinalForm::onFormClosed);
			this->Load += gcnew System::EventHandler(this, &FinalForm::FinalForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FinalForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->CenterToScreen();
		this->pictureBox1->ImageLocation = this->imageLocation;
		this->movieNameLabel->Text = this->movieName;
		this->showDateLabel->Text = this->showDate;
		this->showVersionLabel->Text = this->showVersion;
		this->showRoomLabel->Text =  this->showRoom;
		this->numberOfTicketsLabel->Text = "Ilo�� bilet�w: " + this->numberOfTickets.ToString();
		this->seatsLabel->Text = "Miejsca: " + this->selectedSeats;
		this->ticketPriceLabel->Text = "Zap�acono: " + (15 * this->numberOfTickets) + " z�";
		this->ticketCodeLabel->Text = "Kod: " + this->ticketCode;
	}
	
	private: System::Void onFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
};
}